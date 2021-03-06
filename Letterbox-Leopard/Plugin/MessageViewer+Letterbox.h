//
//  MessageViewer+Letterbox.h
//  Letterbox
//
//  Created by Aaron on 12/3/07.
//  Copyright 2007 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "../AppleHeaders/MessageViewer.h"
@class ASExtendedTableView;

@interface MessageViewer (Letterbox)
// overrides
- (void) Letterbox__setUpWindowContents;
- (BOOL) Letterbox_validateMenuItem:(NSMenuItem *)item;

// actions
- (IBAction) setPreviewPaneRight:(id)sender;
- (IBAction) setPreviewPaneLeft:(id)sender;
- (IBAction) setPreviewPaneBottom:(id)sender;
- (void) setPreviewPanePosition:(NSString *)position;

- (IBAction) hidePreviewPane:(id)sender;
- (IBAction) showPreviewPane:(id)sender;
- (IBAction) togglePreviewPane:(id)sender;

// accessors
- (MessageContentController *) contentController; 
- (ExpandingSplitView *) splitView;
- (ASExtendedTableView *) messageListTableView;

@property BOOL drawsAlternatingRowColors;
@property BOOL drawsDividerLines;
@end
