//
//  UIView+JDFTooltips.h
//  JoeTooltips
//
//  Created by Joe Fryer on 13/11/2014.
//  Copyright (c) 2014 Joe Fryer. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (JDFTooltips)

- (void)jdftt_setFrameWidth:(CGFloat)frameWidth;
- (void)jdftt_setFrameHeight:(CGFloat)frameHeight;

- (void)jdftt_centerInSuperview;
- (void)jdftt_centerHorizontallyInSuperview;
- (void)jdftt_centerVerticallyInSuperview;

@end
