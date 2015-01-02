//
//  JDFTooltipManager.m
//  JoeTooltips
//
//  Created by Joe Fryer on 12/11/2014.
//  Copyright (c) 2014 Joe Fryer. All rights reserved.
//

#import "JDFTooltipManager.h"


@interface JDFTooltipManager ()

@property (nonatomic, strong) NSArray *tooltips;

@end


@implementation JDFTooltipManager

#pragma mark - Getters

- (NSArray *)tooltips
{
    if (!_tooltips) {
        _tooltips = @[];
    }
    return _tooltips;
}

- (UIColor *)backdropColour
{
    if (!_backdropColour) {
        _backdropColour = [UIColor lightGrayColor];
    }
    return _backdropColour;
}


#pragma mark - Init

- (instancetype)initWithHostView:(UIView *)view tooltips:(NSArray *)tooltips;
{
    self = [super init];
    if (self) {
        [self commonInit];
        self.tooltips = tooltips;
        self.hostView = view;
    }
    return self;
}

- (instancetype)initWithHostView:(UIView *)view
{
    self = [self initWithHostView:view tooltips:nil];
    return self;
}

- (void)commonInit
{
    self.showsBackdropView = NO;
    self.backdropAlpha = 0.2f;
    self.backdropTapActionEnabled = YES;
}


#pragma mark - Adding Tooltips (Public)

- (void)addTooltips:(NSArray *)tooltips
{
    NSMutableArray *allTooltips = [self.tooltips mutableCopy];
    for (JDFTooltipView *tooltip in tooltips) {
        if ([tooltip isKindOfClass:[JDFTooltipView class]]) {
            [allTooltips addObject:tooltip];
        }
    }
    self.tooltips = [NSArray arrayWithArray:allTooltips];
}

- (void)addTooltip:(JDFTooltipView *)tooltip
{
    if (![tooltip isKindOfClass:[JDFTooltipView class]]) {
        return;
    }
    
    self.tooltips = [self.tooltips arrayByAddingObject:tooltip];
}

- (void)addTooltipWithTargetPoint:(CGPoint)targetPoint tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection hostView:(UIView *)hostView width:(CGFloat)width
{
    JDFTooltipView *tooltip = [[JDFTooltipView alloc] initWithTargetPoint:targetPoint hostView:hostView tooltipText:tooltipText arrowDirection:arrowDirection width:width];
    [self addTooltip:tooltip];
}

- (void)addTooltipWithTargetPoint:(CGPoint)targetPoint tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection hostView:(UIView *)hostView width:(CGFloat)width showCompletionBlock:(JDFTooltipViewCompletionBlock)showCompletionBlock hideCompletionBlock:(JDFTooltipViewCompletionBlock)hideCompletionBlock
{
    JDFTooltipView *tooltip = [[JDFTooltipView alloc] initWithTargetPoint:targetPoint hostView:hostView tooltipText:tooltipText arrowDirection:arrowDirection width:width showCompletionBlock:showCompletionBlock hideCompletionBlock:hideCompletionBlock];
    [self addTooltip:tooltip];
}

- (void)addTooltipWithTargetView:(UIView *)targetView hostView:(UIView *)hostView tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection width:(CGFloat)width
{
    JDFTooltipView *tooltip = [[JDFTooltipView alloc] initWithTargetView:targetView hostView:hostView tooltipText:tooltipText arrowDirection:arrowDirection width:width];
    [self addTooltip:tooltip];
}

- (void)addTooltipWithTargetView:(UIView *)targetView hostView:(UIView *)hostView tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection width:(CGFloat)width showCompletionBlock:(JDFTooltipViewCompletionBlock)showCompletionBlock hideCompletionBlock:(JDFTooltipViewCompletionBlock)hideCompletionBlock
{
    JDFTooltipView *tooltip = [[JDFTooltipView alloc] initWithTargetView:targetView hostView:hostView tooltipText:tooltipText arrowDirection:arrowDirection width:width showCompletionBlock:showCompletionBlock hideCompletionBlock:hideCompletionBlock];
    [self addTooltip:tooltip];
}

- (void)addTooltipWithTargetBarButtonItem:(UIBarButtonItem *)barButtonItem hostView:(UIView *)hostView tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection width:(CGFloat)width
{
    JDFTooltipView *tooltip = [[JDFTooltipView alloc] initWithTargetBarButtonItem:barButtonItem hostView:hostView tooltipText:tooltipText arrowDirection:arrowDirection width:width];
    [self addTooltip:tooltip];
}

- (void)addTooltipWithTargetBarButtonItem:(UIBarButtonItem *)barButtonItem hostView:(UIView *)hostView tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection width:(CGFloat)width showCompletionBlock:(JDFTooltipViewCompletionBlock)showCompletionBlock hideCompletionBlock:(JDFTooltipViewCompletionBlock)hideCompletionBlock
{
    JDFTooltipView *tooltip = [[JDFTooltipView alloc] initWithTargetBarButtonItem:barButtonItem hostView:hostView tooltipText:tooltipText arrowDirection:arrowDirection width:width showCompletionBlock:showCompletionBlock hideCompletionBlock:hideCompletionBlock];
    [self addTooltip:tooltip];
}


#pragma mark - Showing Tooltips (Public)

- (void)showAllTooltips
{
    if (self.tooltips.count < 1) {
        return;
    }
    
    if (self.showsBackdropView) {
        [self showBackdropView];
    } else {
        [self.backdropView removeFromSuperview];
        self.backdropView = nil;
    }
    for (JDFTooltipView *tooltip in self.tooltips) {
        if (![tooltip isKindOfClass:[JDFTooltipView class]]) {
            continue;
        }
        if (self.showsBackdropView) {
            [tooltip showInView:self.backdropView];
        } else {
            [tooltip show];
        }
    }
}


#pragma mark - Hiding Tooltips (Public)

- (void)hideAllTooltipsAnimated:(BOOL)animated
{
    for (JDFTooltipView *tooltip in self.tooltips) {
        if (![tooltip isKindOfClass:[JDFTooltipView class]]) {
            continue;
        }
        [tooltip hideAnimated:animated];
    }
    [self hideBackdropView];
}


#pragma mark - Public

- (void)setTooltipsNeedLayoutWithHostViewSize:(CGSize)hostViewSize
{
    self.backdropView.frame = self.hostView.window.bounds;
    for (JDFTooltipView *tooltip in self.tooltips) {
        [tooltip setTooltipNeedsLayoutWithHostViewSize:hostViewSize];
    }
}

- (void)setBackgroundColourForAllTooltips:(UIColor *)colour
{
    for (JDFTooltipView *tooltip in self.tooltips) {
        tooltip.tooltipBackgroundColour = colour;
    }
}

- (void)setTextColourForAllTooltips:(UIColor *)colour
{
    for (JDFTooltipView *tooltip in self.tooltips) {
        tooltip.textColour = colour;
    }
}

- (void)setFontForAllTooltips:(UIFont *)font
{
    for (JDFTooltipView *tooltip in self.tooltips) {
        tooltip.font = font;
    }
}

- (void)setShadowEnabledForAllTooltips:(BOOL)shadowEnabled
{
    for (JDFTooltipView *tooltip in self.tooltips) {
        tooltip.shadowEnabled = shadowEnabled;
    }
}

- (void)setShadowColourForAllTooltips:(UIColor *)shadowColour
{
    for (JDFTooltipView *tooltip in self.tooltips) {
        tooltip.shadowColour = shadowColour;
    }
}

- (void)setDismissOnTouchForAllTooltips:(BOOL)dismissOnTouch
{
    for (JDFTooltipView *tooltip in self.tooltips) {
        tooltip.dismissOnTouch = dismissOnTouch;
    }
}


#pragma mark - Backdrop View

- (void)showBackdropViewIfEnabled
{
    if (self.showsBackdropView) {
        [self showBackdropView];
    }
}

- (void)showBackdropView
{
    UIWindow *window = self.hostView.window;
    self.backdropView = [[UIView alloc] initWithFrame:window.bounds];
    UITapGestureRecognizer *tapRecogniser = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleBackdropTap:)];
    [self.backdropView addGestureRecognizer:tapRecogniser];
    self.backdropView.backgroundColor = [self.backdropColour colorWithAlphaComponent:0.0f];
    [window addSubview:self.backdropView];
    [UIView animateWithDuration:0.2 animations:^{
        self.backdropView.backgroundColor = [self.backdropColour colorWithAlphaComponent:self.backdropAlpha];
    }];
}

- (void)hideBackdropView
{
    [UIView animateWithDuration:0.5 animations:^{
        self.backdropView.alpha = 0.0f;
    } completion:^(BOOL finished) {
        [self.backdropView removeFromSuperview];
    }];
}


#pragma mark - Gesture recognisers

- (void)handleBackdropTap:(UIGestureRecognizer *)gestureRecogniser
{
    if (self.backdropTapActionEnabled) {
        [self hideAllTooltipsAnimated:YES];
    }
}

@end
