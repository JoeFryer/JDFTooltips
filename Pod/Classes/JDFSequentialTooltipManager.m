//
//  JDFSequentialTooltipManager.m
//  JoeTooltips
//
//  Created by Joe Fryer on 17/11/2014.
//  Copyright (c) 2014 Joe Fryer. All rights reserved.
//

#import "JDFSequentialTooltipManager.h"


@interface JDFSequentialTooltipManager ()

@property (nonatomic, strong) JDFTooltipView *currentlyShowingTooltip;

@end


@implementation JDFSequentialTooltipManager

#pragma mark - Showing Tooltips

- (void)showNextTooltip
{
    if (self.tooltips.count < 1) {
        return;
    }
    
    if (!self.currentlyShowingTooltip) {
        [self showBackdropViewIfEnabled];
        self.currentlyShowingTooltip = [self.tooltips firstObject];
        [self.currentlyShowingTooltip addTapTarget:self action:@selector(handleTooltipTap:)];
        [self showTooltip:self.currentlyShowingTooltip];
    } else {
        [self.currentlyShowingTooltip hideAnimated:YES];
        
        NSUInteger i = [self.tooltips indexOfObject:self.currentlyShowingTooltip] + 1;
        if (i < self.tooltips.count) {
            self.currentlyShowingTooltip = self.tooltips[i];
            [self.currentlyShowingTooltip addTapTarget:self action:@selector(handleTooltipTap:)];
            [self showTooltip:self.currentlyShowingTooltip];
        } else {
            [self hideBackdropView];
        }
    }
}

- (void)showTooltip:(JDFTooltipView *)tooltip
{
    if (self.showsBackdropView) {
        [tooltip showInView:self.backdropView];
    } else {
        [tooltip show];
    }
}

- (void)showAllTooltips
{
    [self showNextTooltip];
}


#pragma mark - Gesture Recognisers

- (void)handleBackdropTap:(UIGestureRecognizer *)gestureRecogniser
{
    if (self.backdropTapActionEnabled) {
        [self showNextTooltip];
    }
}

- (void)handleTooltipTap:(UIGestureRecognizer *)gestureRecogniser
{
    if (self.currentlyShowingTooltip.dismissOnTouch) {
        [self showNextTooltip];
    }
}

@end
