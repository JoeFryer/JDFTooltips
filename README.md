# JDFTooltips

[![Version](https://img.shields.io/cocoapods/v/JDFTooltips.svg?style=flat)](http://cocoadocs.org/docsets/JDFTooltips)
[![License](https://img.shields.io/cocoapods/l/JDFTooltips.svg?style=flat)](http://cocoadocs.org/docsets/JDFTooltips)
[![Platform](https://img.shields.io/cocoapods/p/JDFTooltips.svg?style=flat)](http://cocoadocs.org/docsets/JDFTooltips)

`JDFTooltips` makes it easy to show tooltip-like popups on iOS (for example, if you want to show instructions/hints to the user the first time they use the app). 

They look a bit like this:

<img src="Screenshots/JDFTooltips.gif" width="300"/>

## Usage

Creating and showing a tooltip is easy. You can create and show a tooltip on its own, like so:

``` objc
JDFTooltipView *tooltip = [[JDFTooltipView alloc] initWithTargetView:self.label1 hostView:self.view tooltipText:@"This is a Tooltip" arrowDirection:JDFTooltipViewArrowDirectionUp width:200.0f];
[tooltip show];
```

Or, if you want to show more than one tooltip, it's probably easier to use one of the manager classes, `JDFTooltipManager` or its subclass `JDFSequentialTooltipManager`.

`JDFTooltipManager` allows you to easily show multiple tooltips at once, and by default it will also show a 'backdrop' behind the tooltips (the user can tap anywhere on the backdrop to dismiss the tooltips). 

`JDFSequentialTooltipManager` allows you to easily show your tooltips sequentially; one is shown at a time, with the next one being shown after the previous one is dismissed. `JDFSequentialTooltipManager` also shows a backdrop by a default - tapping it moves to the next tooltip in the sequence. 

These manager classes also provide convenience methods for configuring stuff (background colour, text colour, font etc) on the all of the tooltips they are managing, and convenience methods for creating tooltips.

**If you are using a tooltip manager, you should keep a strong reference to it.**

**Note: If you have the backdrop enabled, you should not show your tooltips from within `viewDidLoad` - you should instead show them from `viewDidAppear:`. This is a know issue that will be fixed in the future.**

`JDFSequentialTooltipManager` example:

``` objc
    // In your interface
    @property (nonatomic, strong) JDFSequentialTooltipManager *tooltipManager;
    
    // Somewhere in your implementation
    self.tooltipManager = [[JDFSequentialTooltipManager alloc] initWithHostView:self.view];
    [self.tooltipManager addTooltipWithTargetView:view1 hostView:self.view tooltipText:@"Tooltip 1" arrowDirection:JDFTooltipViewArrowDirectionUp width:200.0f];
    [self.tooltipManager addTooltipWithTargetView:view2 hostView:self.view tooltipText:@"Tooltip 2" arrowDirection:JDFTooltipViewArrowDirectionUp width:200.0f];
    [self.tooltipManager addTooltipWithTargetView:view3 hostView:self.view tooltipText:@"Tooltip 3" arrowDirection:JDFTooltipViewArrowDirectionDown width:200.0f];
    [self.tooltipManager showNextTooltip];
```

## Demo

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Installation

JDFTooltips is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

    pod "JDFTooltips"

If you're not using CocoaPods, simply copy everything from `Pod\Classes` into your project.

## Author

Joe Fryer, joe.d.fryer@gmail.com

[@JoeFryer88 on Twitter](https://twitter.com/joefryer88)

## License

JDFTooltips is available under the MIT license. See the LICENSE file for more info.

## Release Notes

#### 1.0

Initial Release

#### 1.1

 - Improved tooltip showing/hiding animation
 - Bug Fix: JDFSequentialTooltipManager no longer bypasses a tooltip's dismissOnTouch setting.

