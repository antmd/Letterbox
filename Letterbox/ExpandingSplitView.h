#import <Cocoa/Cocoa.h>

@interface ExpandingSplitView : NSSplitView
{
    float _oldSplitPosition;
    int dividerToolTipTag;
    NSString *toolTipString;
    NSImage *splitterDimple;
    NSImage *splitterBackground;
    BOOL useSpecialDivider;
}

- (void)dealloc;
- (void)finalize;
- (void)setUseSpecialDivider:(BOOL)fp8;
- (void)mouseDown:(id)fp8;
- (float)getSplitPercentage;
- (BOOL)_isSubviewAtIndexVisible:(unsigned int)fp8;
- (BOOL)isSecondViewVisible;
- (BOOL)isFirstViewVisible;
- (void)resizeSubviewsToPercentage:(float)fp8;
- (void)setDividerToolTip:(id)fp8;
- (float)dividerThickness;
- (struct _NSRect)dividerRect;
- (void)drawDividerInRect:(struct _NSRect)fp8;
- (id)accessibilityAttributeValue:(id)fp8;

@end