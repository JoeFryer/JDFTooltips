//
//  UILabel+JDFTooltips.m
//  JoeTooltips
//
//  Created by Joe Fryer on 13/11/2014.
//  Copyright (c) 2014 Joe Fryer. All rights reserved.
//

#import "UILabel+JDFTooltips.h"

// Categories
#import "UIView+JDFTooltips.h"


@implementation UILabel (JDFTooltips)

- (void)jdftt_resizeHeightToFitTextContents
{
    self.numberOfLines = 0;
    if (self.text.length < 1) {
        return;
    }
    [self jdftt_setFrameHeight:[self jdftt_requiredHeightToFitContents]];
}

- (void)jdftt_resizeWidthToFitTextContents
{
    self.numberOfLines = 0;
    if (self.text.length < 1) {
        return;
    }
    [self jdftt_setFrameWidth:[self jdftt_requiredWidthToFitContents]];
}

- (CGFloat)jdftt_requiredHeightToFitContents
{
    if (self.text.length < 1) {
        return 0.0f;
    }
    NSAttributedString *attributedText = [[NSAttributedString alloc] initWithString:self.text attributes:@{NSFontAttributeName: self.font}];
    CGRect rect = [attributedText boundingRectWithSize:CGSizeMake(self.frame.size.width, CGFLOAT_MAX) options:NSStringDrawingUsesLineFragmentOrigin context:nil];
    return ceil(rect.size.height);
}

- (CGFloat)jdftt_requiredWidthToFitContents
{
    if (self.text.length < 1) {
        return 0.0f;
    }
    NSAttributedString *attributedText = [[NSAttributedString alloc] initWithString:self.text attributes:@{NSFontAttributeName: self.font}];
    CGRect rect = [attributedText boundingRectWithSize:CGSizeMake(CGFLOAT_MAX, self.frame.size.height) options:NSStringDrawingUsesLineFragmentOrigin context:nil];
    return ceil(rect.size.width);
}

@end
