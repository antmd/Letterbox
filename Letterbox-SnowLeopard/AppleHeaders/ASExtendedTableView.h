#import <Cocoa/Cocoa.h>

@interface ASExtendedTableView : NSTableView
{
    struct {
        unsigned int delegateScrolls:1;
        unsigned int delegateProvidesDragImage:1;
        unsigned int delegateProvidesSourceDraggingMask:1;
        unsigned int delegateDoesCommandBySelector:1;
        unsigned int delegateDragWillEnd:1;
        unsigned int delegateDragWillEndOperation:1;
        unsigned int delegateDraggedImageMovedTo:1;
        unsigned int delegateProvidesBackgroundColor:1;
        unsigned int delegateProvidesBackgroundShadedRegions:1;
        unsigned int alwaysKeepColumnsSizedToFitAvailableSpace:1;
        unsigned int delegateProvidesColumnsToPinInPlace:1;
        unsigned int delegateProvidesHighlightStyle:1;
        unsigned int delegateProvidesHighlightColor:1;
        unsigned int delegateRespondsToWillDrawRowsInRange:1;
        unsigned int delegateRespondsToDidDrawRowsInRange:1;
        unsigned int delegateApprovesScrolling:1;
        unsigned int delegateRespondsToGotEvent:1;
        unsigned int delegateRespondsToShouldBeginDrag:1;
        unsigned int delegateRespondsToWillResizeColumnsToFit:1;
        unsigned int delegateRespondsToDidResizeColumnsToFit:1;
        unsigned int delegateRespondsToWillMoveToWindow:1;
        unsigned int delegateRespondsToDidMoveToWindow:1;
        unsigned int delegateRespondsToDidEndLiveResize:1;
    } _extendedTableViewFlags;
    BOOL _didLazyLoadMenu;
}

- (void)awakeFromNib;
- (void)finalize;
- (BOOL)_wantsLiveResizeToUseCachedImage;
- (void)viewDidEndLiveResize;
- (void)keyDown:(id)fp8;
- (void)setDelegate:(id)fp8;
- (id)menu;
- (struct _NSRange)completelyVisibleRowsCapacity:(int *)fp8;
- (void)stopObservingViewBoundsChange:(id)fp8;
- (void)startObservingViewBoundsChange:(id)fp8;
- (void)viewWillMoveToSuperview:(id)fp8;
- (void)asetvSuperviewBoundsChanged:(id)fp8;
- (void)showTableColumnsFromArray:(id)fp8 allColumns:(id)fp12;
- (id)getPersistentTableColumnsAsArray;
- (void)scrollRowToVisible:(int)fp8;
- (void)setTableColumn:(id)fp8 toVisible:(BOOL)fp12 atPosition:(int)fp16;
- (void)moveColumn:(int)fp8 toColumn:(int)fp12;
- (void)setAlwaysKeepColumnsSizedToFitAvailableSpace:(BOOL)fp8;
- (BOOL)alwaysKeepColumnsSizedToFitAvailableSpace;
- (float)totalWidthOfAllColumns;
- (int)numberOfColumnsToPinToLefthandSide;
- (int)_columnClosestToColumn:(int)fp8 whenMoved:(float)fp12;
- (void)betterSizeToFit;
- (void)sizeToFit;
- (void)_sizeToFitIfNecessary;
- (id)dragImageForRowsWithIndexes:(id)fp8 tableColumns:(id)fp12 event:(id)fp16 offset:(struct _NSPoint *)fp20;
- (void)draggedImage:(id)fp8 endedAt:(struct _NSPoint)fp12 operation:(unsigned int)fp20;
- (void)draggedImage:(id)fp8 movedTo:(struct _NSPoint)fp12;
- (void)_userSelectRow:(int)fp8 byExtendingSelection:(BOOL)fp12;
- (BOOL)shouldUseSecondaryHighlightColor;
- (id)_highlightColorForCell:(id)fp8;
- (void)_highlightRect:(struct _NSRect)fp8 withColor:(id)fp24 usingStyle:(int)fp28;
- (void)_colorizeRow:(int)fp8 inRect:(struct _NSRect)fp12 clipRect:(struct _NSRect)fp28;
- (void)drawBackgroundInClipRect:(struct _NSRect)fp8;
- (void)drawRect:(struct _NSRect)fp8;
- (void)drawRow:(int)fp8 clipRect:(struct _NSRect)fp12;
- (struct _NSRect)cellFrameForPaddedRect:(struct _NSRect)fp8;
- (struct _NSRect)paddedRectForCellFrame:(struct _NSRect)fp8;
- (struct _NSRect)frameOfCellAtColumn:(int)fp8 row:(int)fp12;
- (int)_distanceInDragDirectionBeforeDragAttempt;
- (int)_distanceInNonDragDirectionBeforeAbortingDragAttempt;
- (unsigned int)draggingSourceOperationMaskForLocal:(BOOL)fp8;
- (void)mouseDown:(id)fp8;
- (void)mouseUp:(id)fp8;
- (void)_postEventNotification:(id)fp8 fromCell:(id)fp12;
- (BOOL)_dragShouldBeginFromMouseDown:(id)fp8;
- (void)viewWillMoveToWindow:(id)fp8;
- (void)viewDidMoveToWindow;

@end

