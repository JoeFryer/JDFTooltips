//
//  JDFSequentialTooltipManager.h
//  JoeTooltips
//
//  Created by Joe Fryer on 17/11/2014.
//  Copyright (c) 2014 Joe Fryer. All rights reserved.
//

#import "JDFTooltipManager.h"


/**
 *  JDFSequentialTooltipManager is a subclass of JDFTooltipManager that allows you to show tooltips sequentially instead of all at-once.
 
 *  By default, tapping a tooltip or the backdrop triggers @c showNextTooltip (showing the next tooltip, or finishing the sequence and hiding everything).
 */
@interface JDFSequentialTooltipManager : JDFTooltipManager

#pragma mark - Showing Tooltips
/**
 *  Hides the manager's current tooltip (if there is a tooltip currently showing) and shows the next one.
 
 *  Tooltips are shown in the order they are added.
 
 *  If there an no more tooltips to be shown, the last tooltip and the backdrop are hidden.
 */
- (void)showNextTooltip;

@end
