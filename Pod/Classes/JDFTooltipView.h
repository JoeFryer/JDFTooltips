//
//  JDFTooltipView.h
//  JoeTooltips
//
//  Created by Joe Fryer on 12/11/2014.
//  Copyright (c) 2014 Joe Fryer. All rights reserved.
//

#import <UIKit/UIKit.h>


#pragma mark - JDFTooltipViewArrowDirection
/**
 *  Possible directions in which a JDFTooltipView's arrow will point.
 */
typedef NS_ENUM(NSInteger, JDFTooltipViewArrowDirection){
    /**
     *  The arrow is on top of the tooltip, pointing up.
     */
    JDFTooltipViewArrowDirectionUp,
    /**
     *  The arrow is on the right of the tooltip, pointing to the right.
     */
    JDFTooltipViewArrowDirectionRight,
    /**
     *  The arrow is on the bottom of the tooltip, pointing down.
     */
    JDFTooltipViewArrowDirectionDown,
    /**
     *  The arrow is on the left of the tooltip, pointing to the left.
     */
    JDFTooltipViewArrowDirectionLeft
};


#pragma mark - JDFTooltipViewCompletionBlock
/**
 *  Completion block for JDFTooltipView animation completions. No paramaters, no return value.
 */
typedef void (^JDFTooltipViewCompletionBlock)(void);



// *****
// ****************************************************
            #pragma mark - JDFTooltipView
// ****************************************************
// *****
/**
 *  JDFTooltipView is a UIView subclass that allows you to easily show a 'tooltip' style view to the user. The tooltips look like a small popover containing some text, with an arrow on one of the edges that points to a point of interest (typically another view) to which the text refers.
 */
@interface JDFTooltipView : UIView

#pragma mark Tooltip Text

/**
 *  The text that is displayed in the tooltip.
 */
@property (nonatomic, copy) NSString *tooltipText;

/**
 *  The colour of the tooltip text. Default is @c white.
 */
@property (nonatomic, strong) UIColor *textColour;

/**
 *  The alignment of the tooltip text. Default is NSTextAlignmentCenter.
 */
@property (nonatomic) NSTextAlignment textAlignment;

/**
 *  The line break mode of the tooltip text. Default is NSLineBreakByTruncatingTail.
 */
@property (nonatomic) NSLineBreakMode lineBreakMode;

/**
 *  The number of lines of the tooltip text. Default is 0 (no limit).
 */
@property (nonatomic) NSInteger numberOfLines;

/**
 *  The font for the text shown in the tooltip.
 */
@property (nonatomic, strong) UIFont *font;


#pragma mark Other Options

/**
 *  The background colour for the tooltip. Default is @c darkGray.
 */
@property (nonatomic, strong) UIColor *tooltipBackgroundColour;

/**
 *  The direction that the tooltip's arrow will point
 */
@property (nonatomic) JDFTooltipViewArrowDirection arrowDirection;

/**
 *  Indicates whether or not the tooltip has a shadow. Default is @c YES.
 */
@property (nonatomic) BOOL shadowEnabled;

/**
 *  The colour of the shadow. Default is @c gray.
 */
@property (nonatomic, strong) UIColor *shadowColour;

/**
 *  Indicates whether the tooltip will dismiss itself when it is touched.
 */
@property (nonatomic) BOOL dismissOnTouch;


#pragma mark Initialisation
/**
 *  Initialises A JDFTooltipView with the arrow at the specified point. If you want to support interface orientation, you will need to do so manually for a tooltip created with this initialiser. If you want rotation to be handled automatically, you should use one of the initWithTargetView: or initWithTargetBarButtonItem: methods instead.
 *
 *  @param targetPoint    The point at which the tooltip's arrow points.
 *  @param hostView       The view in which the tooltip will be displayed.
 *  @param tooltipText    The text displayed in the tooltip.
 *  @param arrowDirection The direction of the tooltip's arrow.
 *  @param width          The width of the tooltip. If the text goes beyond this width, the tooltip will be resized vertically to accomodate it.
 *
 *  @return An initialised JDFTooltipView.
 */
- (instancetype)initWithTargetPoint:(CGPoint)targetPoint hostView:(UIView *)hostView tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection width:(CGFloat)width;

/**
 *  Initialises A JDFTooltipView with the arrow at the specified point. If you want to support interface orientation, you will need to do so manually for a tooltip created with this initialiser. If you want rotation to be handled automatically, you should use one of the initWithTargetView: or initWithTargetBarButtonItem: methods instead.
 *
 *  @param targetPoint         The point at which the tooltip's arrow points.
 *  @param hostView            The view in which the tooltip will be displayed.
 *  @param tooltipText         The text displayed in the tooltip.
 *  @param arrowDirection      The direction of the tooltip's arrow.
 *  @param width               The width of the tooltip. If the text goes beyond this width, the tooltip will be resized vertically to accomodate it.
 *  @param showCompletionBlock A block that gets executed after the tooltip is shown.
 *  @param hideCompletionBlock A block that gets executed after the tooltip has been dismissed.
 *
 *  @return An initialised JDFTooltipView.
 */
- (instancetype)initWithTargetPoint:(CGPoint)targetPoint hostView:(UIView *)hostView tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection width:(CGFloat)width showCompletionBlock:(JDFTooltipViewCompletionBlock)showCompletionBlock hideCompletionBlock:(JDFTooltipViewCompletionBlock)hideCompletionBlock;

/**
 *  Initialises a JDFTooltipView. The tooltip will try to position the arrow pointing towards the targetView, in the specified direction.
 *
 *  @param targetView     The focus of the tooltip. The tooltip will attempt to point the arrow towards the targetView.
 *  @param hostView       The view in which the tooltip will be displayed.
 *  @param tooltipText    The text displayed in the tooltip.
 *  @param arrowDirection The direction of the tooltip's arrow.
 *  @param width          The width of the tooltip. If the text goes beyond this width, the tooltip will be resized vertically to accomodate it.
 *
 *  @return An initialised JDFTooltipView.
 */
- (instancetype)initWithTargetView:(UIView *)targetView hostView:(UIView *)hostView tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection width:(CGFloat)width;

/**
 *  Initialises a JDFTooltipView. The tooltip will try to position the arrow pointing towards the targetView, in the specified direction.
 *
 *  @param targetView     The focus of the tooltip. The tooltip will attempt to point the arrow towards the targetView.
 *  @param hostView       The view in which the tooltip will be displayed.
 *  @param tooltipText    The text displayed in the tooltip.
 *  @param arrowDirection The direction of the tooltip's arrow.
 *  @param width          The width of the tooltip. If the text goes beyond this width, the tooltip will be resized vertically to accomodate it.
 *  @param showCompletionBlock A block that gets executed after the tooltip is shown.
 *  @param hideCompletionBlock A block that gets executed after the tooltip has been dismissed.
 *
 *  @return An initialised JDFTooltipView.
 */
- (instancetype)initWithTargetView:(UIView *)targetView hostView:(UIView *)hostView tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection width:(CGFloat)width showCompletionBlock:(JDFTooltipViewCompletionBlock)showCompletionBlock hideCompletionBlock:(JDFTooltipViewCompletionBlock)hideCompletionBlock;

/**
 *  Initialises a JDFTooltipView. The tooltip will try to position the arrow pointing towards the barButtonItem, in the specified direction.
 *
 *  @param barButtonItem  The focus of the tooltip. The tooltip will attempt to point the arrow towards the targetView.
 *  @param hostView       The view in which the tooltip will be displayed.
 *  @param tooltipText    The text displayed in the tooltip.
 *  @param arrowDirection The direction of the tooltip's arrow.
 *  @param width          The width of the tooltip. If the text goes beyond this width, the tooltip will be resized vertically to accomodate it.
 *
 *  @return An initialised JDFTooltipView.
 */
- (instancetype)initWithTargetBarButtonItem:(UIBarButtonItem *)barButtonItem hostView:(UIView *)hostView tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection width:(CGFloat)width;

/**
 *  Initialises a JDFTooltipView. The tooltip will try to position the arrow pointing towards the barButtonItem, in the specified direction.
 *
 *  @param barButtonItem  The focus of the tooltip. The tooltip will attempt to point the arrow towards the targetView.
 *  @param hostView       The view in which the tooltip will be displayed.
 *  @param tooltipText    The text displayed in the tooltip.
 *  @param arrowDirection The direction of the tooltip's arrow.
 *  @param width          The width of the tooltip. If the text goes beyond this width, the tooltip will be resized vertically to accomodate it.
 *  @param showCompletionBlock A block that gets executed after the tooltip is shown.
 *  @param hideCompletionBlock A block that gets executed after the tooltip has been dismissed.
 *
 *  @return An initialised JDFTooltipView.
 */
- (instancetype)initWithTargetBarButtonItem:(UIBarButtonItem *)barButtonItem hostView:(UIView *)hostView tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection width:(CGFloat)width showCompletionBlock:(JDFTooltipViewCompletionBlock)showCompletionBlock hideCompletionBlock:(JDFTooltipViewCompletionBlock)hideCompletionBlock;

#pragma mark Showing/Hiding Tooltips
/**
 *  Shows the tooltip.
 */
- (void)show;

/**
 *  Shows the tooltip in the specified view.
 *
 *  @param view The view to show the tooltip in.
 */
- (void)showInView:(UIView *)view;

/**
 *  Hides the tooltip, optionally animated.
 *
 *  @param animated BOOL determining whether to animate the hide or not.
 */
- (void)hideAnimated:(BOOL)animated;

#pragma mark Gesture Recognising
/**
 *  Adds a target/action for taps on the tooltip.
 *
 *  @param target The target.
 *  @param action The Selector.
 */
- (void)addTapTarget:(id)target action:(SEL)action;

#pragma mark Layout
/**
 *  You should call this method when the tooltip needs to lay itself out again e.g. to handle rotation, or if the targetView has moved. This method only has an effect when there is a targetView. If you used one of the withPoint: initialisers, this method will have no effect.
 *
 *  @param hostViewSize The new size of the host view.
 */
- (void)setTooltipNeedsLayoutWithHostViewSize:(CGSize)hostViewSize;

@end
