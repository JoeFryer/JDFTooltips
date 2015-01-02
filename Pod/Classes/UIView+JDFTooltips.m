//
//  UIView+JDFTooltips.m
//  JoeTooltips
//
//  Created by Joe Fryer on 13/11/2014.
//  Copyright (c) 2014 Joe Fryer. All rights reserved.
//

#import "UIView+JDFTooltips.h"

@implementation UIView (JDFTooltips)

- (void)jdftt_setFrameWidth:(CGFloat)frameWidth
{
    CGRect frame = self.frame;
    frame.size.width = frameWidth;
    self.frame = frame;
}

- (void)jdftt_setFrameHeight:(CGFloat)frameHeight
{
    CGRect frame = self.frame;
    frame.size.height = frameHeight;
    self.frame = frame;
}

- (void)jdftt_centerInSuperview
{
    [self jdftt_centerHorizontallyInSuperview];
    [self jdftt_centerVerticallyInSuperview];
}

- (void)jdftt_centerHorizontallyInSuperview
{
    CGFloat viewWidth = self.frame.size.width;
    CGFloat superviewWidth = self.superview.frame.size.width;
    
    CGRect frame = self.frame;
    frame.origin.x = (superviewWidth - viewWidth) / 2;
    self.frame = frame;
}

- (void)jdftt_centerVerticallyInSuperview
{
    CGFloat viewHeight = self.frame.size.height;
    CGFloat superviewHeight = self.superview.frame.size.height;
    
    CGRect frame = self.frame;
    frame.origin.y = (superviewHeight - viewHeight) / 2;
    self.frame = frame;
}

@end
