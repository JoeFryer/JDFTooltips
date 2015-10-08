//
//  JDFTooltipManager.h
//  JoeTooltips
//
//  Created by Joe Fryer on 12/11/2014.
//  Copyright (c) 2014 Joe Fryer. All rights reserved.
//

#import <UIKit/UIKit.h>

// Tooltips
#import "JDFTooltipView.h"


/**
 *  JDFTooltipManager manages a set of JDFTooltipViews. It assists in showing the tooltips, and provides the option to show a backdrop behind the tooltips while they are showing.
 
    Add tooltips to the manager either by creating them yourself then using addTooltip:/addTooltips:, or by using one of the convenience methods provided.
 
    Calling showAllTooltips: will show all of the tooltips at once. If you wish to show them sequentially instead, you should use JDFTSequentialTooltipManager instead. Use hideAllTooltipsAnimated: to hide all tooltips.
 */
@interface JDFTooltipManager : NSObject

#pragma mark Views

/**
 *  The tooltips currently being managed by the JDFTooltipManager
 */
@property (nonatomic, readonly) NSArray *tooltips;

/**
 *  The view in which the tooltips (and the backdrop view) are shown.
 */
@property (nonatomic, weak) UIView *hostView;

/**
 *  The Backdrop view. This is the view that gets shown on top of the hostView, usually with an alpha < 1.0 so that the host view can be seen below it (if the backdrop is enabled).
 *
 *  This is generally only intended to be used by subclasses. You can modify its colour/alpha,
 */
@property (nonatomic, strong) UIView *backdropView;


#pragma mark Options

/**
 *  Indicates whether a backdrop view is shown when the tooltips are shown. Default is @c NO.
 */
@property (nonatomic) BOOL showsBackdropView;

/**
 *  The background colour of the backdrop view. Default is @c lightGray.
 */
@property (nonatomic, strong) UIColor *backdropColour;

/**
 *  The alpha value of the backdropView. The default is @c 0.2
 */
@property (nonatomic) CGFloat backdropAlpha;

/**
 *  Indicates whether a tap on the backdropView triggers an action. For JDFTooltipManager, this action is hideAllTooltipsAnimated:. Default is YES.
 */
@property (nonatomic) BOOL backdropTapActionEnabled;


#pragma mark Tooltip Option Convenience Methods

/**
 *  Sets the background colour of the tooltips that are being managed by the tooltip manager. This method ONLY effects tooltips that have already been added to the manager; any tooltips added after calling this method will not be affected.
 *
 *  @param colour The colour to be set.
 */
- (void)setBackgroundColourForAllTooltips:(UIColor *)colour;

/**
 *  Sets the text colour for all of the tooltips that are being managed by the tooltip manager. This method ONLY effects tooltips that have already been added to the manager; any tooltips added after calling this method will not be affected.
 *
 *  @param colour The colour to be set.
 */
- (void)setTextColourForAllTooltips:(UIColor *)colour;

/**
 *  Sets the font for all of the tooltips that are being managed by the tooltip manager. This method ONLY effects tooltips that have already been added to the manager; any tooltips added after calling this method will not be affected.
 *
 *  @param font The font to be set.
 */
- (void)setFontForAllTooltips:(UIFont *)font;

/**
 *   Sets the shadowEnabled property for all of the tooltips that are being managed by the tooltip manager. This method ONLY effects tooltips that have already been added to the manager; any tooltips added after calling this method will not be affected.
 *
 *  @param shadowEnabled BOOL indicating whether the shadow should be enabled or not.
 */
- (void)setShadowEnabledForAllTooltips:(BOOL)shadowEnabled;

/**
 *  Sets the shadowColour property for all of the tooltips that are being managed by the tooltip manager. This method ONLY effects tooltips that have already been added to the manager; any tooltips added after calling this method will not be affected.
 *
 *  @param shadowColour The colour to be set as the tooltips' shadowColour.
 */
- (void)setShadowColourForAllTooltips:(UIColor *)shadowColour;

/**
 *   Sets the dismissOnTouch property for all of the tooltips that are being managed by the tooltip manager. This method ONLY effects tooltips that have already been added to the manager; any tooltips added after calling this method will not be affected.
 *
 *  @param dismissOnTouch BOOL indicating whether the tooltips should dismiss on touch or not.
 */
- (void)setDismissOnTouchForAllTooltips:(BOOL)dismissOnTouch;


#pragma mark Initialisation

/**
 *  Returns an initialised JDFTooltipManager for use showing tooltips in the specified view.
 *
 *  @param view The view in which tooltips will be shown (as well as the backdropView).
 *
 *  @return An initialised JDFTooltipManager.
 */
- (instancetype)initWithHostView:(UIView *)view;

/**
 *  Returns an initialised JDFTooltipManager for use showing tooltips in the specified view, with the supplied tooltips.
 *
 *  @param view     The view in which tooltips will be shown (as well as the backdropView).
 *  @param tooltips An array of JDFTooltipViews to be added to the manager
 *
 *  @return An initialised JDFTooltipManager.
 */
- (instancetype)initWithHostView:(UIView *)view tooltips:(NSArray *)tooltips;


#pragma mark Adding Tooltips

/**
 *  Adds the supplied tooltips to the manager.
 *
 *  @param tooltips An array of JDFToolipViews.
 */
- (void)addTooltips:(NSArray *)tooltips;

/**
 *  Adds the supplied tooltip to the manager.
 *
 *  @param tooltip The JDFTooltipView to be added to the manager.
 */
- (void)addTooltip:(JDFTooltipView *)tooltip;

/**
 *  Initialises a JDFTooltipView with @c initWithTargetPoint:hostView:tooltipText:arrowDirection:width: and adds it to the manager.
 *
 *  @param targetPoint    The target point for the arrow.
 *  @param tooltipText    The tooltip text.
 *  @param arrowDirection The direction of the arrow.
 *  @param hostView       The Host View that the tooltip will be shown in.
 *  @param width          The width of the tooltip. If the text goes beyond this width, the tooltip will be resized vertically to accomodate it.
 */
- (void)addTooltipWithTargetPoint:(CGPoint)targetPoint tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection hostView:(UIView *)hostView width:(CGFloat)width;

/**
 *  Initialises a JDFTooltipView with @c initWithTargetPoint:hostView:tooltipText:arrowDirection:width:showCompletionBlock:hideCompletionBlock: and adds it to the manager.
 *
 *  @param targetPoint          The target point for the arrow.
 *  @param tooltipText          The tooltip text.
 *  @param arrowDirection       The direction of the arrow.
 *  @param hostView             The Host View that the tooltip will be shown in.
 *  @param width                The width of the tooltip. If the text goes beyond this width, the tooltip will be resized vertically to accomodate it.
 *  @param showCompletionBlock  Completion block that is executed after the tooltip is shown.
 *  @param hideCompletionBlock  Completion block that is executed after the tooltip is hidden.
 */
- (void)addTooltipWithTargetPoint:(CGPoint)targetPoint tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection hostView:(UIView *)hostView width:(CGFloat)width showCompletionBlock:(JDFTooltipViewCompletionBlock)showCompletionBlock hideCompletionBlock:(JDFTooltipViewCompletionBlock)hideCompletionBlock;

/**
 *  Initialises a JDFTooltipView with @c initWithTargetView:hostView:tooltipText:arrowDirection:width: and adds it to the manager.
 *
 *  @param targetView     The target view that the tooltip will point towards.
 *  @param hostView       The Host View that the tooltip will be shown in.
 *  @param tooltipText    The tooltip text.
 *  @param arrowDirection The direction of the arrow.
 *  @param width          The width of the tooltip. If the text goes beyond this width, the tooltip will be resized vertically to accomodate it.
 */
- (void)addTooltipWithTargetView:(UIView *)targetView hostView:(UIView *)hostView tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection width:(CGFloat)width;

/**
 *  Initialises a JDFTooltipView with @c initWithTargetView:hostView:tooltipText:arrowDirection:width:showCompletionBlock:hideCompletionBlock: and adds it to the manager.
 *
 *  @param targetView           The target view that the tooltip will point towards.
 *  @param hostView             The Host View that the tooltip will be shown in.
 *  @param tooltipText          The tooltip text.
 *  @param arrowDirection       The direction of the arrow.
 *  @param width                The width of the tooltip. If the text goes beyond this width, the tooltip will be resized vertically to accomodate it.
 *  @param showCompletionBlock  Completion block that is executed after the tooltip is shown.
 *  @param hideCompletionBlock  Completion block that is executed after the tooltip is hidden.
 */
- (void)addTooltipWithTargetView:(UIView *)targetView hostView:(UIView *)hostView tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection width:(CGFloat)width showCompletionBlock:(JDFTooltipViewCompletionBlock)showCompletionBlock hideCompletionBlock:(JDFTooltipViewCompletionBlock)hideCompletionBlock;

/**
 *  Initialises a JDFTooltipView with @c initWithTargetBarButtonItem:hostView:tooltipText:arrowDirection:width: and adds it to the manager.
 *
 *  @param barButtonItem        The target bar button item that the tooltip will point towards.
 *  @param hostView             The Host View that the tooltip will be shown in.
 *  @param tooltipText          The tooltip text.
 *  @param arrowDirection       The direction of the arrow.
 *  @param width                The width of the tooltip. If the text goes beyond this width, the tooltip will be resized vertically to accomodate it.
 */
- (void)addTooltipWithTargetBarButtonItem:(UIBarButtonItem *)barButtonItem hostView:(UIView *)hostView tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection width:(CGFloat)width;

/**
 *  Initialises a JDFTooltipView with @c initWithTargetBarButtonItem:hostView:tooltipText:arrowDirection:width:showCompletionBlock:hideCompletionBlock and adds it to the manager.
 *
 *  @param barButtonItem        The target bar button item that the tooltip will point towards.
 *  @param hostView             The Host View that the tooltip will be shown in.
 *  @param tooltipText          The tooltip text.
 *  @param arrowDirection       The direction of the arrow.
 *  @param width                The width of the tooltip. If the text goes beyond this width, the tooltip will be resized vertically to accomodate it.
 *  @param showCompletionBlock  Completion block that is executed after the tooltip is shown.
 *  @param hideCompletionBlock  Completion block that is executed after the tooltip is hidden.
 */
- (void)addTooltipWithTargetBarButtonItem:(UIBarButtonItem *)barButtonItem hostView:(UIView *)hostView tooltipText:(NSString *)tooltipText arrowDirection:(JDFTooltipViewArrowDirection)arrowDirection width:(CGFloat)width showCompletionBlock:(JDFTooltipViewCompletionBlock)showCompletionBlock hideCompletionBlock:(JDFTooltipViewCompletionBlock)hideCompletionBlock;


#pragma mark Showing/Hiding Tooltips

/**
 *  Shows all tooltips.
 */
- (void)showAllTooltips;

/**
 *  Hides all tooltips, optionally animated.
 *
 *  @param animated Indicates whether the tooltips hiding should be animated or not.
 */
- (void)hideAllTooltipsAnimated:(BOOL)animated;


#pragma mark Showing/Hiding the Backdrop view.

/**
 *  If showsBackdropView == YES, the backdropView will be shown.
 */
- (void)showBackdropViewIfEnabled;

/**
 *  Hides the backdropView.
 */
- (void)hideBackdropView;


#pragma mark Layout

/**
 *  Lets the tooltip manager know that it needs to layout its tooltips, for example in response to an orientation change.
 *
 *  The tooltip manager will then inform each of its tooltips that it needs to update its layout. Tooltips will update their layout relative to their targetView or targetBarButtonItem  (tooltips will not update their layout if they were created with a targetPoint, as noted in the initialiser documentation).
 *
 *  @param hostViewSize The new size of the tooltips hostView.
 */
- (void)setTooltipsNeedLayoutWithHostViewSize:(CGSize)hostViewSize;


#pragma mark Methods for subclasses.

/**
 *  Gesture recogniser method for taps on the backdropView. This method is only intended to be overriden by subclasses.
 *
 *  @param gestureRecogniser The gesture recogniser that sent the message.
 */
- (void)handleBackdropTap:(UIGestureRecognizer *)gestureRecogniser;

@end
