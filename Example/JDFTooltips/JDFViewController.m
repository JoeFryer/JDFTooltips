//
//  JDFViewController.m
//  JDFTooltips
//
//  Created by Joe Fryer on 12/21/2014.
//  Copyright (c) 2014 Joe Fryer. All rights reserved.
//

#import "JDFViewController.h"

// Tooltips
#import "JDFTooltips.h"


@interface JDFViewController ()

// Tooltips
@property (nonatomic, strong) JDFSequentialTooltipManager *tooltipManager;

// Views
@property (nonatomic, strong) UILabel *label1;
@property (nonatomic, strong) UILabel *label2;
@property (nonatomic, strong) UILabel *label3;

// Bar Buttons
@property (nonatomic, strong) UIBarButtonItem *showWithBackdropButton;
@property (nonatomic, strong) UIBarButtonItem *showWithoutBackdropButton;

@end


@implementation JDFViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];

    CGFloat padding = 30.0f;
    CGFloat labelWidth = self.view.frame.size.width - (padding * 2);
    CGFloat labelHeight = 20.0f;
    
    UILabel *label1 = [[UILabel alloc] initWithFrame:CGRectMake(padding, 100.0f, labelWidth, labelHeight)];
    label1.text = @"This is a label";
    label1.textAlignment = NSTextAlignmentCenter;
    [self.view addSubview:label1];
    self.label1 = label1;
    
    UILabel *label2 = [[UILabel alloc] initWithFrame:CGRectMake(padding, CGRectGetMaxY(label1.frame) + 100.0f, labelWidth, labelHeight)];
    label2.text = @"This is another label";
    label2.textAlignment = NSTextAlignmentCenter;
    [self.view addSubview:label2];
    self.label2 = label2;
    
    UILabel *label3 = [[UILabel alloc] initWithFrame:CGRectMake(padding, self.view.frame.size.height - labelHeight - padding, labelWidth, labelHeight)];
    label3.text = @"The third label";
    label3.textAlignment = NSTextAlignmentCenter;
    [self.view addSubview:label3];
    self.label3 = label3;
    
    self.showWithBackdropButton = [[UIBarButtonItem alloc] initWithTitle:@"Show (Backrop)" style:UIBarButtonItemStylePlain target:self action:@selector(showWithBackdropButtonPressed:)];
    self.navigationItem.leftBarButtonItem = self.showWithBackdropButton;
    
    self.showWithoutBackdropButton = [[UIBarButtonItem alloc] initWithTitle:@"Show (No Backdrop)" style:UIBarButtonItemStylePlain target:self action:@selector(showWithoutBackdropButtonPressed:)];
    self.navigationItem.rightBarButtonItem = self.showWithoutBackdropButton;
    
    [self showWithBackdropButtonPressed:nil];
}


#pragma mark - Button Actions

- (void)showWithBackdropButtonPressed:(UIBarButtonItem *)sender
{
    CGFloat tooltipWidth = 260.0f;
    
    self.tooltipManager = [[JDFSequentialTooltipManager alloc] initWithHostView:self.view];
    [self.tooltipManager addTooltipWithTargetView:self.label1 hostView:self.view tooltipText:@"This is a tooltip with the backrop enabled. Tap anywhere to advance to the next tooltip." arrowDirection:JDFTooltipViewArrowDirectionUp width:tooltipWidth];
    [self.tooltipManager addTooltipWithTargetView:self.label2 hostView:self.view tooltipText:@"This is another tooltip.  You can choose which direction the arrow points; this one is pointing up." arrowDirection:JDFTooltipViewArrowDirectionUp width:tooltipWidth];
    [self.tooltipManager addTooltipWithTargetView:self.label3 hostView:self.view tooltipText:@"This is the last tooltip. Tap anywhere to finish the sequence." arrowDirection:JDFTooltipViewArrowDirectionDown width:tooltipWidth];
    self.tooltipManager.showsBackdropView = YES;
    [self.tooltipManager showNextTooltip];
}

- (void)showWithoutBackdropButtonPressed:(UIBarButtonItem *)sender
{
    self.showWithBackdropButton.enabled = NO;
    self.showWithoutBackdropButton.enabled = NO;
    
    CGFloat tooltipWidth = 260.0f;
    
    self.tooltipManager = [[JDFSequentialTooltipManager alloc] initWithHostView:self.view];
    [self.tooltipManager addTooltipWithTargetView:self.label1 hostView:self.view tooltipText:@"This is a tooltip with the backdrop disabled. Tap on the tooltip itself to advance to the next tooltip." arrowDirection:JDFTooltipViewArrowDirectionUp width:tooltipWidth];
    [self.tooltipManager addTooltipWithTargetView:self.label2 hostView:self.view tooltipText:@"This is another tooltip.  You can choose which direction the arrow points; this one is pointing up." arrowDirection:JDFTooltipViewArrowDirectionUp width:tooltipWidth];
    
    __weak JDFViewController *weakSelf = self;
    [self.tooltipManager addTooltipWithTargetView:self.label3 hostView:self.view tooltipText:@"This is the last tooltip." arrowDirection:JDFTooltipViewArrowDirectionDown width:tooltipWidth showCompletionBlock:nil hideCompletionBlock:^{
        weakSelf.showWithBackdropButton.enabled = YES;
        weakSelf.showWithoutBackdropButton.enabled = YES;
    }];
    self.tooltipManager.showsBackdropView = NO;
    [self.tooltipManager showNextTooltip];
}

@end
