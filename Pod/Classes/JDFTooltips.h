//
//  JDFTooltips.h
//  JoeTooltips
//
//  Created by Joe Fryer on 10/12/2014.
//  Copyright (c) 2014 Joe Fryer. All rights reserved.
//

#ifndef JoeTooltips_JDFTooltips_h
#define JoeTooltips_JDFTooltips_h


#endif

#import "JDFTooltipView.h"
#import "JDFSequentialTooltipManager.h"
#import "JDFTooltipManager.h"


/**
 Todo (high priority):
 - Empty. Woo!
 */

/**
 Todo (low priority):
 - Check the managers - will the view that is initially supplied as the hostView for a tooltip be superceded by the hostView on the manager? Is this correct?
 - If, for example, being shown from a non-full-screen modal on iPad, make sure it can overflow outside of the modal itself.
 - Maybe revisit the logic for positioning the tooltips (better centring etc)
 - In some cases (different positions), the tooltips 'move' if they are shown repeatedly.
 - Allow showing without an arrow
 - Allow showing an image/icon instead/as well?
 - Auto-dismiss option after specified time.
 - Managers - change the convenience methods to affect tooltips that are added later
 - Add the backdrop to the host instead of the host's window? Or the keyWindow?
 - Add completion blocks to the managers.
 - Documentation - mention that all tooltips in a single manager need to have the same hostView for orientation to work. (They do, don't they?).
 - Allow using tabBarItems as targets?
 - Add some kind of layout block, so that you can supply your own code for laying out the tooltip (useful for allowing you to use targetPoint and still suporting rotation).
 - More shadow customisation options?
 - setTooltipNeedsLayoutWithHostViewSize: - do we need to supply the size here?
 - Add the ability to adjust the positioning relative to a view (move further up by x etc)
 - JDFTooltipSequentialManager (sequentially show all in one go, with kind of quick bubbling effect as well?)
 - Managers - Completion blocks (on hide etc.)

 */

