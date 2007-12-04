#import <Cocoa/Cocoa.h>

#import "MessageContentController.h"

@class MessageHeaderView;
@class MessageTextContainer;
@class MessageViewingState;

@interface MessageHeaderDisplay : NSObject
{
    MessageHeaderView *headerView;
    MessageContentController *contentController;
    MessageTextContainer *specialContainer;
    NSImageView *senderImageView;
    NSString *unloadedSender;
    float oldHeaderViewWidth;
    BOOL isCalculatingAddressLines;
    BOOL isForPrinting;
    BOOL isViewingSource;
    MessageViewingState *_viewingState;
}

+ (id)copyHeadersForMessage:(id)fp8 viewingState:(id)fp12;
+ (id)_copyRSSHeadersForMessage:(id)fp8 viewingState:(id)fp12;
+ (void)_addAddressesToString:(id)fp8 addressStrings:(id)fp12 plainAddresses:(id)fp16 addressAttachments:(id)fp20 key:(id)fp24 viewingState:(id)fp28 tabPosition:(int)fp32 range:(struct _NSRange *)fp36;
+ (void)_setSendersFromAddressAttachments:(id)fp8;
+ (void)_stripTrailingReturns:(id)fp8;
+ (void)setUpAttachmentsDescriptionForMessage:(id)fp8 viewingState:(id)fp12;
+ (id)formattedAttachmentsSizeForAttachments:(id)fp8;
+ (id)formattedAttachmentsSizeForMessage:(id)fp8;
+ (int)numberOfAddressesThatFitOnTwoLinesAttachments:(id)fp8 strings:(id)fp12 inTextContainer:(id)fp16 withIndent:(int)fp20 andVerticalLocation:(int)fp24 forPrinting:(BOOL)fp28;
+ (id)linkForMoreAddressesCount:(int)fp8 headerKey:(id)fp12 font:(id)fp16;
+ (id)copyViewingState:(id)fp8;
+ (void)setUpEncryptionAndSignatureImageForMessage:(id)fp8 viewingState:(id)fp12;
+ (id)orderedKeys:(id)fp8 withTableViewOrder:(id)fp12;
+ (id)regularParagraphStyleForTabPosition:(int)fp8;
+ (id)regularParagraphStyleForTabPosition:(int)fp8 paragraphSpacing:(int)fp12;
+ (id)addressParagraphStyleForTabPosition:(int)fp8 withLineBreakMode:(unsigned int)fp12 forPrinting:(BOOL)fp16;
+ (void)setTabsWithPosition:(int)fp8 inAttributedString:(id)fp12 withKeys:(id)fp16 addressKeys:(id)fp20 addressAttachments:(id)fp24 forPrinting:(BOOL)fp28;
+ (id)attributedStringOfLength:(int)fp8 usingAttachments:(id)fp12 startingAtIndex:(int)fp16 strings:(id)fp20 newAttachments:(id *)fp24 forPrinting:(BOOL)fp28;
+ (void)rangeOfAddresses:(struct _NSRange *)fp8 rangeOfLink:(struct _NSRange *)fp12 forKey:(id)fp16 inAttributedString:(id)fp20;
- (void)dealloc;
- (id)viewingState;
- (void)setViewingState:(id)fp8;
- (void)awakeFromNib;
- (void)setUp;
- (id)unloadedSender;
- (void)setUnloadedSender:(id)fp8;
- (void)display:(id)fp8;
- (void)prepareToRemoveView;
- (void)displayAttributedString:(id)fp8;
- (void)headerViewFrameChanged:(id)fp8;
- (void)recalculateAddressLinesShouldDisplay:(BOOL)fp8;
- (void)updateSubjectURLMatches:(id)fp8;
- (void)showAllAddressesForKey:(id)fp8;
- (BOOL)textView:(id)fp8 clickedOnLink:(id)fp12 atIndex:(unsigned int)fp16;
- (void)adjustFontSizeBy:(int)fp8 viewingState:(id)fp12;
- (id)selectedText;
- (void)_addressBookChanged:(id)fp8;
- (void)_addressPhotoLoaded:(id)fp8;
- (id)textView;
- (void)textView:(id)fp8 clickedOnCell:(id)fp12 event:(id)fp16 inRect:(struct _NSRect)fp20 atIndex:(unsigned int)fp36;
- (void)layoutManager:(id)fp8 didCompleteLayoutForTextContainer:(id)fp12 atEnd:(BOOL)fp16;
- (void)setIsForPrinting:(BOOL)fp8;

@end

