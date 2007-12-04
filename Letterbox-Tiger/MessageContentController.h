#import <Cocoa/Cocoa.h>

@class Message;
@class ActivityMonitor;
@class TextMessageDisplay;
@class MessageHeaderDisplay;
@class AttachmentsView;
@class ObjectCache;
@class InvocationQueue;
@class MessageViewingState;

@interface MessageContentController : NSResponder
{
    Message *_message;
    MessageViewingState *_viewingState;
    ActivityMonitor *_documentMonitor;
    id _currentDisplay;
    id _threadDisplay;
    TextMessageDisplay *textDisplay;
    MessageHeaderDisplay *headerDisplay;
    NSView *contentContainerView;
    NSView *junkMailView;
    NSTextField *junkMailMessageField;
    NSButton *junkMailLoadHTMLButton;
    NSView *loadImagesView;
    NSButton *loadImagesButton;
    NSBox *bannerBorderBox;
    NSView *certificateView;
    NSButton *certificateButton;
    NSImageView *certificateImage;
    NSTextField *certificateMessageField;
    NSView *childBannerView;
    NSTextField *childBannerMessageField;
    NSImageView *childBannerImage;
    NSButton *childBannerButton;
    NSButton *childBannerHelpButton;
    NSView *parentBannerView;
    NSTextField *parentBannerMessageField;
    NSImageView *parentBannerImage;
    NSButton *parentBannerButton;
    NSView *parentApprovedOrRejectedBannerView;
    NSTextField *parentApprovedOrRejectedBannerMessageField;
    NSImageView *parentApprovedOrRejectedBannerImage;
    AttachmentsView *attachmentsView;
    ObjectCache *_documentCache;
    InvocationQueue *invocationQueue;
    double _foregroundLoadStartTime;
    double _backgroundLoadStartTime;
    double _backgroundLoadEndTime;
    NSString *_messageIDToRestoreInitialStateFor;
    struct _NSRect _initialVisibleRect;
    struct _NSRange _initialSelectedRange;
    NSArray *mostRecentHeaderOrder;
    NSTimer *_fadeTimer;
    NSView *_currentBanner;
    BOOL _hideBannerBorder;
    NSTextField *_widthResizableTextFieldInCurrentBanner;
    NSView *_rightNeighborOfWidthResizableTextFieldInCurrentBanner;
    BOOL isForPrinting;
    BOOL showDefaultHeadersStickily;
    MessageViewingState *stickyViewingState;
}

+ (void)setClass:(Class)fp8 forDisplayType:(id)fp12;
- (id)init;
- (void)setIsForPrinting:(BOOL)fp8;
- (void)setContentContainerView:(id)fp8;
- (void)setLoadImagesView:(id)fp8;
- (void)setJunkMailView:(id)fp8;
- (void)setCertificateView:(id)fp8;
- (void)setChildBannerView:(id)fp8;
- (void)setParentBannerView:(id)fp8;
- (void)setParentApprovedOrRejectedBannerView:(id)fp8;
- (void)readDefaultsFromDictionary:(id)fp8;
- (void)writeDefaultsToDictionary:(id)fp8;
- (void)dealloc;
- (void)stopAllActivity;
- (id)documentView;
- (id)currentDisplay;
- (void)_updateIfDisplayingMessage:(id)fp8;
- (void)_fetchDataForMessageAndUpdateDisplay:(id)fp8;
- (void)_messageMayHaveBecomeAvailable;
- (id)_messageTilingView;
- (void)fadeToEmpty;
- (void)_pushDocumentToCache;
- (void)_backgroundLoadFinished:(id)fp8;
- (void)_backgroundUrlificationFinished:(id)fp8 urlMatches:(id)fp12;
- (void)setMessage:(id)fp8 headerOrder:(id)fp12;
- (void)_setMessage:(id)fp8 headerOrder:(id)fp12;
- (void)_fetchContentsForMessage:(id)fp8 fromStore:(id)fp12 withViewingState:(id)fp16;
- (void)_startBackgroundLoad:(id)fp8;
- (id)message;
- (void)setMostRecentHeaderOrder:(id)fp8;
- (void)reloadCurrentMessage;
- (void)viewerPreferencesChanged:(id)fp8;
- (void)showJunkMailHelp:(id)fp8;
- (void)_removeCurrentBanner;
- (void)_bannerResized:(id)fp8;
- (void)_showBannerView:(id)fp8;
- (void)_showLoadImagesBanner;
- (void)_showCertificateBanner;
- (id)_fixBezelStyleOfHelpButtonInBannerView:(id)fp8;
- (void)_showJunkBanner;
- (BOOL)_showBannerIfMessageIsOutgoingMessageWaitingForParentApproval;
- (BOOL)_showBannerIfMessageIsPermissionRequestFromChild;
- (void)_updateBanner;
- (void)setShowBannerBorder:(BOOL)fp8;
- (void)setShowRevealMessageLink:(BOOL)fp8;
- (BOOL)showRevealMessageLink;
- (void)_addRecentAddress:(id)fp8;
- (void)markAsNotJunkMailClicked:(id)fp8;
- (void)_setJunkLevelToNotJunk;
- (void)approveChildRequest:(id)fp8;
- (void)rejectChildRequest:(id)fp8;
- (void)sendMessage:(id)fp8;
- (void)_messageFlagsDidChange:(id)fp8;
- (void)_updateDisplay;
- (void)_setCurrentDisplay:(id)fp8;
- (void)highlightSearchText:(id)fp8;
- (id)attachmentsView;
- (id)textView;
- (id)selectedText;
- (id)selectedWebArchive;
- (id)attachmentsInSelection;
- (id)webArchive;
- (void)clearCache;
- (id)viewingState;
- (id)viewingStateForMessage:(id)fp8;
- (void)cacheViewingState:(id)fp8 forMessage:(id)fp12;
- (void)displayString:(id)fp8;
- (void)initPrintInfo;
- (int)headerDetailLevel;
- (BOOL)showingAllHeaders;
- (void)setShowAllHeaders:(BOOL)fp8;
- (BOOL)remoteAttachmentsAreDownloaded;
- (void)makeStickyInfoFromViewingState:(id)fp8;
- (void)makeStickyShowDefaultHeaders;
- (void)keyDown:(id)fp8;
- (BOOL)pageDown;
- (BOOL)pageUp;
- (BOOL)currentlyViewingSource;
- (BOOL)_validateAction:(SEL)fp8 tag:(int)fp12;
- (id)findTarget;
- (BOOL)validateToolbarItem:(id)fp8 forSegment:(int)fp12;
- (BOOL)validateMenuItem:(id)fp8;
- (void)showAllHeaders:(id)fp8;
- (void)showFilteredHeaders:(id)fp8;
- (void)viewSource:(id)fp8;
- (void)toggleShowControlCharacters:(id)fp8;
- (void)toggleAttachmentsArea:(id)fp8;
- (void)showFirstAlternative:(id)fp8;
- (void)showPreviousAlternative:(id)fp8;
- (void)showNextAlternative:(id)fp8;
- (void)_messageWouldHaveLoadedRemoteURL:(id)fp8;
- (void)downloadRemoteContent:(id)fp8;
- (void)showCertificate:(id)fp8;
- (void)showBestAlternative:(id)fp8;
- (void)changeTextEncoding:(id)fp8;
- (void)makeFontBigger:(id)fp8;
- (void)makeFontSmaller:(id)fp8;
- (void)jumpToSelection:(id)fp8;
- (void)takeFindStringFromSelection:(id)fp8;
- (void)saveAttachments:(id)fp8;

@end
