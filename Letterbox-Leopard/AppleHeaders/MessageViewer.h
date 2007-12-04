#import <Cocoa/Cocoa.h>
@protocol MVMailboxSelectionOwner
- (id)selectedMailboxes;
- (id)selectedMailbox;
- (id)sortedSectionItemsForTimeMachine;
- (BOOL)isSelectedMailboxSpecial;
- (void)selectPathsToMailboxes:(id)fp8;
- (BOOL)mailboxIsExpanded:(id)fp8;
- (BOOL)sectionIsExpanded:(id)fp8;
- (void)revealMailbox:(id)fp8;
- (id)mailboxSelectionWindow;
@end

@protocol MailboxesOutlineViewControllerDelegate
- (void)selectAllMessages;
- (void)focusMessages;
@end

@class MessageMall;
@class TableViewManager;
@class MessageContentController;
@class MailboxesOutlineViewController;
@class ExpandingSplitView;
@class MailVerticalSplitView;
@class ColorBackgroundView;
@class ActivityViewController;
@class ToDoListController;
@class ToDoMall;
@class ToDoListView;
@class MessageViewerLazyPopUpButton;
@class VerticalSplitViewHandle;
@class MailboxPaneBottomView;
@class SplitterAnimation;
@class SearchSliceView;
@class SearchTextField;

@interface MessageViewer : NSResponder <MVMailboxSelectionOwner, MailboxesOutlineViewControllerDelegate>
{
    MessageMall *_messageMall;
    TableViewManager *_tableManager;
    MessageContentController *_contentController;
    MailboxesOutlineViewController *_outlineViewController;
    NSWindow *_window;
    ExpandingSplitView *_splitView;
    NSScrollView *_messageListScrollView;
    MailVerticalSplitView *_verticalSplitView;
    ColorBackgroundView *_viewerContainer;
    ColorBackgroundView *_mailboxesView;
    ActivityViewController *_activityViewController;
    SearchTextField *_searchField;
    NSView *_searchFieldView;
    NSToolbarItem *_searchViewItem;
    NSString *_lastSearchPhrase;
    int _currentSearchArea;
    int _currentSearchField;
    int _currentSearchTarget;
    int _selectedTag;
    NSMenu *_tableHeaderMenu;
    ToDoListController *_toDoController;
    ToDoMall *_toDoMall;
    NSScrollView *_toDoScrollView;
    ToDoListView *_toDoListView;
    NSMenu *_toDoColumnsMenu;
    NSMenu *_toDoSortByMenu;
    NSMenu *_messageColumnsMenu;
    NSMenu *_messageSortByMenu;
    NSMenuItem *_columnsMenuItem;
    NSMenuItem *_sortByMenuItem;
    BOOL _toDoListViewIsShowing;
    BOOL _previewPaneWasVisibleWhenToDoListWasShown;
    NSArray *_toDoMailboxes;
    MessageViewerLazyPopUpButton *newMailboxButton;
    MessageViewerLazyPopUpButton *actionButton;
    VerticalSplitViewHandle *verticalSplitViewHandle;
    MailboxPaneBottomView *mailboxPaneBottomView;
    BOOL _shouldPreventTableViewResize;
    BOOL _shouldMakeTableViewSelectionVisible;
    BOOL _shouldMakeMessageSelectionVisible;
    BOOL _showingDefaultSearchString;
    BOOL _updatingSearchField;
    BOOL _allowShowingDeletedMessages;
    BOOL _suppressWindowTitleUpdates;
    BOOL _didSetupUI;
    float _restoreMailboxPaneToWidthAfterDragOperation;
    float _lastSplitViewPosition;
    float _lastMailboxSplitPosition;
    float _lastDragXPosition;
    NSArray *_mailboxesToDisplayWhenVisible;
    NSToolbar *_toolbar;
    NSMutableDictionary *_toolbarItems;
    NSDictionary *_savedDefaults;
    NSMutableArray *_transferOperations;
    NSMutableDictionary *_viewerContents;
    float _splitViewPositionBeforeSearch;
    SplitterAnimation *_animation;
    SearchSliceView *_searchSliceView;
    BOOL _updatingToolbar;
    float _mailboxesViewWidthAtLastToolbarUpdate;
}

+ (void)initialize;
+ (id)allMessageViewers;
+ (id)allSingleMessageViewers;
+ (id)existingViewerForStore:(id)fp8;
+ (id)existingViewerForMailboxUid:(id)fp8;
+ (id)existingViewerForMessage:(id)fp8;
+ (id)_mailboxUidForTag:(unsigned int)fp8;
+ (id)newViewerForMailboxWithTag:(unsigned int)fp8;
+ (id)existingViewerShowingMessage:(id)fp8;
+ (void)registerNewViewer:(id)fp8;
+ (void)deregisterViewer:(id)fp8;
+ (void)showAllViewers;
+ (id)mailboxUidsBeingViewed;
+ (id)frontmostMessageViewer;
+ (void)searchForString:(id)fp8;
+ (id)_mailboxUidsForPaths:(id)fp8;
+ (void)saveDefaultsWithDelay;
+ (void)saveDefaults;
+ (void)restoreFromDefaults;
- (void)revealMessage:(id)fp8;
- (void)revealCurrentMessage;
- (void)_displayFollowup:(id)fp8;
- (void)_cantFindFollowupToMessage:(id)fp8;
- (void)showFollowupsToMessage:(id)fp8;
- (id)_mailboxUidsFromDefaults:(id)fp8;
- (id)initWithSavedDefaults:(id)fp8;
- (id)init;
- (id)plainInit;
- (id)initWithMailboxUids:(id)fp8;
- (void)dealloc;
- (void)_registerForApplicationNotifications;
- (void)_unregisterForApplicationNotifications;
- (void)_registerForStoreNotifications;
- (void)_unregisterForStoreNotifications;
- (void)storeBeingInvalidated:(id)fp8;
- (void)_setStore:(id)fp8;
- (BOOL)_isViewingMailboxUid:(id)fp8;
- (BOOL)_isViewingMessage:(id)fp8;
- (BOOL)_isShowingMessage:(id)fp8;
- (id)window;
- (void)show;
- (void)showAndMakeKey:(BOOL)fp8;
- (void)_setupUIAndOrderFront:(BOOL)fp8 andMakeKey:(BOOL)fp12;
- (id)tableHeaderViewGetDefaultMenu:(id)fp8;
- (id)_toDoController;
- (void)_setUpWindowContents;
- (void)_setupMailboxOutlineView;
- (void)_setupNextKeyViewLoop;
- (void)_setUpMenus;
- (void)takeOverAsSelectionOwner;
- (void)resignAsSelectionOwner;
- (void)windowDidBecomeMain:(id)fp8;
- (void)nowWouldBeAGoodTimeToTerminate:(id)fp8;
- (BOOL)windowShouldClose:(id)fp8;
- (void)windowWillMiniaturize:(id)fp8;
- (void)openMailboxesPaneToWidth:(float)fp8 byAnimating:(BOOL)fp12;
- (BOOL)mailboxesPaneIsOpen;
- (BOOL)mailboxesPaneIsOpenWideEnoughToUse;
- (void)splitViewDidResizeSubviews:(id)fp8;
- (void)splitViewWillResizeSubviews:(id)fp8;
- (void)dividerDidEndDragSession:(id)fp8;
- (void)splitViewDoubleClickedOnDivider:(id)fp8;
- (void)toggleMailboxesPane:(id)fp8;
- (void)splitView:(id)fp8 resizeSubviewsWithOldSize:(struct _NSSize)fp12;
- (BOOL)splitView:(id)fp8 canCollapseSubview:(id)fp12;
- (float)splitView:(id)fp8 constrainMinCoordinate:(float)fp12 ofSubviewAt:(int)fp16;
- (float)splitView:(id)fp8 constrainMaxCoordinate:(float)fp12 ofSubviewAt:(int)fp16;
- (float)maxMailboxesViewWidthAllowed;
- (float)idealMailboxesViewWidth;
- (void)updateMailboxButtonVisibilityForWidth:(float)fp8;
- (float)splitView:(id)fp8 constrainSplitPosition:(float)fp12 ofSubviewAt:(int)fp16;
- (id)selectedMailboxes;
- (id)selectedMailbox:(BOOL)fp8;
- (id)selectedMailbox;
- (BOOL)isSelectedMailboxSpecial;
- (void)selectPathsToMailboxes:(id)fp8;
- (BOOL)mailboxIsExpanded:(id)fp8;
- (BOOL)sectionIsExpanded:(id)fp8;
- (id)expandedItems;
- (id)sortedSectionItemsForTimeMachine;
- (void)revealMailbox:(id)fp8;
- (id)mailboxSelectionWindow;
- (void)setSelectedMailboxes:(id)fp8;
- (id)selectedMessages;
- (void)setSelectedMessages:(id)fp8;
- (id)currentDisplayedMessage;
- (void)outlineViewDoubleClick:(id)fp8;
- (void)selectMailbox:(id)fp8;
- (void)_openBrowserForMessages:(id)fp8;
- (void)keyDown:(id)fp8;
- (void)keyUp:(id)fp8;
- (void)_mailboxWasRenamed:(id)fp8;
- (void)mailboxSelectionChanged:(id)fp8;
- (void)_mallDidOpen;
- (void)_mallStructureDidChange;
- (void)_accountsDidChange:(id)fp8;
- (void)smartMailboxCriteriaChanged:(id)fp8;
- (void)_setMailboxUids:(id)fp8;
- (BOOL)_selectionContainsMessagesWithDeletedStatusEqualTo:(BOOL)fp8;
- (BOOL)_selectionContainsMessagesWithReadStatusEqualTo:(BOOL)fp8;
- (BOOL)_selectionContainsMessagesWithFlaggedStatusEqualTo:(BOOL)fp8;
- (BOOL)_selectionContainsMessagesWithJunkMailLevelEqualTo:(int)fp8;
- (BOOL)_selectionContainsMessagesWithAttachments;
- (BOOL)atLeastOneSelectedMessageIsInOutbox:(id)fp8;
- (BOOL)atLeastOneSelectedMessageIsInDrafts:(id)fp8;
- (BOOL)_validateActionForToDoList:(SEL)fp8 tag:(int)fp12;
- (BOOL)_validateAction:(SEL)fp8 tag:(int)fp12;
- (BOOL)validateMenuItem:(id)fp8;
- (void)messageWasDisplayedInTextView:(id)fp8;
- (void)messageThreadSummaryWasDisplayedInTextView:(id)fp8;
- (void)checkNewMail:(id)fp8;
- (void)replyMessage:(id)fp8;
- (void)replyAllMessage:(id)fp8;
- (void)replyToSender:(id)fp8;
- (void)replyToOriginalSender:(id)fp8;
- (void)showComposeWindow:(id)fp8;
- (BOOL)_showEditorForNote:(id)fp8;
- (void)showNoteEditor:(id)fp8;
- (void)showAddressPanel:(id)fp8;
- (void)toggleAttachmentsArea:(id)fp8;
- (void)undeleteMessages:(id)fp8;
- (void)deleteMessages:(id)fp8;
- (void)deleteMessagesAllowingMoveToTrash:(BOOL)fp8;
- (void)openMessages:(id)fp8;
- (void)selectAllMessages;
- (void)focusMessages;
- (void)focusMailboxes;
- (void)focusMessage;
- (void)replyViaIM:(id)fp8;
- (void)showAccountInfo:(id)fp8;
- (id)tableManager;
- (id)mailboxesOutlineViewController;
- (void)jumpToSelection:(id)fp8;
- (id)editorWithType:(int)fp8;
- (void)redirectMessage:(id)fp8;
- (void)forwardMessage:(id)fp8;
- (void)forwardAsAttachment:(id)fp8;
- (void)showToDoReferencedMessageInNewWindow:(id)fp8;
- (void)showToDoInList:(id)fp8;
- (id)currentSingleSelectedToDoMailbox;
- (void)displaySelectedMessageInSeparateWindow:(id)fp8;
- (void)renameMailbox:(id)fp8;
- (void)moveMessagesToMailbox:(id)fp8;
- (void)copyMessagesToMailbox:(id)fp8;
- (id)_selectedMessagesWhoseFlag:(unsigned long)fp8 isEqualToState:(BOOL)fp12;
- (void)_changeFlag:(id)fp8 state:(BOOL)fp12 forMessages:(id)fp16 undoActionName:(id)fp20;
- (void)markAsRead:(id)fp8;
- (void)markAsUnread:(id)fp8;
- (void)markAsReadFromToolbar:(id)fp8;
- (void)markAsUnreadFromToolbar:(id)fp8;
- (void)markAsUnflagged:(id)fp8;
- (void)markAsFlagged:(id)fp8;
- (void)markAsFlaggedFromToolbar:(id)fp8;
- (void)markAsUnflaggedFromToolbar:(id)fp8;
- (void)changeColor:(id)fp8;
- (void)rebuildTableOfContents:(id)fp8;
- (void)_putMessageDataOntoPasteboard:(id)fp8 attributedString:(id)fp12 shouldDelete:(id)fp16 pasteboardType:(id)fp20;
- (void)_copyMessagesToPasteboard:(id)fp8 deleteWhenCopied:(BOOL)fp12 pasteboardType:(id)fp16 alternateType:(id)fp20;
- (void)_progressAlertDidEnd:(id)fp8 returnCode:(int)fp12 contextInfo:(void *)fp16;
- (void)_showActivityProgressPanelForCopy:(id)fp8;
- (BOOL)_doCopy:(id)fp8 deleteWhenCopied:(BOOL)fp12;
- (void)copy:(id)fp8;
- (void)cut:(id)fp8;
- (int)pasteMessages:(id)fp8 todosByMessage:(id)fp12 unsuccessfulMessages:(id)fp16 flagsToSet:(id)fp20 destinationAccount:(id)fp24 destinationStore:(id)fp28;
- (void)addToDosFromDictionary:(id)fp8 forMessages:(id)fp12 newDocumentIDsByOld:(id)fp16 destinationAccount:(id)fp20;
- (void)_pasteData:(id)fp8 pasteboardType:(id)fp12 alternateData:(id)fp16 alternateType:(id)fp20 destination:(id)fp24;
- (void)paste:(id)fp8;
- (void)startSpeaking:(id)fp8;
- (void)stopSpeaking:(id)fp8;
- (void)speechSynthesizer:(id)fp8 didFinishSpeaking:(BOOL)fp12;
- (void)showPrintPanel:(id)fp8;
- (BOOL)send:(id)fp8 forDraft:(BOOL)fp12 actualMessage:(id)fp16;
- (BOOL)send:(id)fp8 forDraft:(BOOL)fp12;
- (BOOL)send:(id)fp8;
- (void)saveAs:(id)fp8;
- (void)saveAllAttachments:(id)fp8;
- (void)quickLookSelectedAttachments:(id)fp8;
- (id)defaultSearchString;
- (void)showDefaultSearchString;
- (id)_criterionForMailbox:(id)fp8;
- (id)mailboxSearchCriterionForScope:(int)fp8 containsSentMailbox:(char *)fp12 containsTrashMailbox:(char *)fp16 shouldExcludeJunk:(char *)fp20;
- (void)searchIndex:(id)fp8;
- (BOOL)_isShowingSearchResults;
- (unsigned int)_searchResultCount;
- (BOOL)_canSaveSearchWithTarget:(int)fp8;
- (BOOL)_canSearchSelectedMailboxes;
- (void)_showSearchSliceView;
- (void)_hideSearchSliceViewByAnimating:(BOOL)fp8;
- (void)_searchForString:(id)fp8;
- (void)_updateSearchStatus;
- (void)_clearSearchByAnimating:(BOOL)fp8;
- (void)clearSearch:(id)fp8;
- (void)setupSearchParametersForTag:(int)fp8;
- (int)searchField;
- (int)searchTarget;
- (int)searchArea;
- (void)controlTextDidEndEditing:(id)fp8;
- (void)controlTextDidChange:(id)fp8;
- (void)_removeAttachmentsFromMessages:(id)fp8 fromStores:(id)fp12;
- (void)removeAttachments:(id)fp8;
- (void)scrollBodyToShowToDo:(id)fp8;
- (id)todoTextFromDisplaySelection;
- (BOOL)createToDoWithViewAsKey:(id)fp8;
- (void)_selectAndRevealToDoMailboxForAccount:(id)fp8;
- (id)firstCreateToDoResponder;
- (void)createToDo:(id)fp8;
- (void)sortByTagOfSender:(id)fp8;
- (void)focus:(id)fp8;
- (void)unfocus:(id)fp8;
- (void)openAllThreads:(id)fp8;
- (void)closeAllThreads:(id)fp8;
- (void)toggleThreadedMode:(id)fp8;
- (void)selectThread:(id)fp8;
- (void)selectPreviousInThread:(id)fp8;
- (void)selectNextInThread:(id)fp8;
- (void)showDeletions:(id)fp8;
- (void)hideDeletions:(id)fp8;
- (void)toggleContentsColumn:(id)fp8;
- (void)toggleMessageNumbersColumn:(id)fp8;
- (void)toggleMessageFlagsColumn:(id)fp8;
- (void)toggleFromColumn:(id)fp8;
- (void)togglePresenceColumn:(id)fp8;
- (void)toggleToColumn:(id)fp8;
- (void)toggleDateSentColumn:(id)fp8;
- (void)toggleDateReceivedColumn:(id)fp8;
- (void)toggleLocationColumn:(id)fp8;
- (void)toggleAuthorColumn:(id)fp8;
- (void)toggleSizeColumn:(id)fp8;
- (void)writeDefaultsToArray:(id)fp8;
- (id)_saveDefaults;
- (void)_loadDefaults;
- (void)_setupFromDefaults;
- (id)_countStringForType:(int)fp8 isDrafts:(BOOL)fp12 omitUnread:(BOOL)fp16 totalCount:(unsigned int *)fp20;
- (void)_messageUpdated:(id)fp8;
- (void)_documentsTransferred:(id)fp8;
- (void)_updateWindowTitle;
- (void)_reallyUpdateWindowTitle;
- (void)_updateMallUids:(id)fp8;
- (id)_currentMessageManager;
- (void)_setSplitViewPercentage:(float)fp8 animate:(BOOL)fp12;
- (void)animationDidEnd:(id)fp8;
- (void)messageWasSelected:(id)fp8 fromMessageBrowserController:(id)fp12;
- (void)scrollCurrentlySelectedMessageToTop;
- (void)messageWasDoubleClicked:(id)fp8;
- (void)messageBrowserView:(id)fp8 willStartDragWithEvent:(id)fp12;
- (void)draggedImage:(id)fp8 movedTo:(struct _NSPoint)fp12;
- (void)messageBrowserViewDidEndDragging:(id)fp8;
- (BOOL)transferSelectedMessagesToMailbox:(id)fp8 deleteOriginals:(BOOL)fp12;
- (BOOL)deleteMessages:(id)fp8 allowMoveToTrash:(BOOL)fp12 allowUndo:(BOOL)fp16;
- (void)_reallyAnimateProgressInidicator;
- (void)_updateSearchStatusWithDelay;
- (void)threadDidExpand;
- (void)threadDidCollapse;
- (void)clearUndoRedoStacks;
- (void)searchWillStart;
- (void)searchDidFinish;
- (void)searchDidUpdate;
- (id)selectedMailboxUids;
- (void)performSearch:(id)fp8;
- (void)saveSearch:(id)fp8;
- (void)reapplySortingRules:(id)fp8;
- (void)_returnToSenderSheetDidEnd:(id)fp8 returnCode:(int)fp12 contextInfo:(void *)fp16;
- (void)_bounceMessages:(id)fp8;
- (void)returnToSender:(id)fp8;
- (void)addSenderToAddressBook:(id)fp8;
- (void)markAsJunkMail:(id)fp8;
- (void)markMessagesAsJunkMail:(id)fp8 stores:(id)fp12;
- (void)_deleteJunkedMessages:(id)fp8 inStores:(id)fp12 moveToTrash:(BOOL)fp16;
- (void)synchronouslyMarkAsJunkMail:(id)fp8 inStores:(id)fp12 delete:(BOOL)fp16;
- (void)undoMarkMessagesAsJunkMail:(id)fp8 stores:(id)fp12;
- (void)markAsNotJunkMail:(id)fp8;
- (void)markMessagesAsNotJunkMail:(id)fp8 stores:(id)fp12;
- (void)synchronouslyMarkAsNotJunkMail:(id)fp8 inStores:(id)fp12;
- (BOOL)_transferMessages:(id)fp8 toMailbox:(id)fp12 deleteOriginals:(BOOL)fp16 allowUndo:(BOOL)fp20 isDeleteOperation:(BOOL)fp24;
- (void)_reportError:(id)fp8;
- (void)transfer:(id)fp8 didCompleteWithError:(id)fp12;
- (void)selectMessagesForUndo:(id)fp8;
- (id)undoManagerForMessageTransfer:(id)fp8;
- (void)_updateSearchItemLabel;

@end

@interface MessageViewer (AppleScript)
- (id)uniqueID;
- (id)objectSpecifier;
- (id)allMessages;
- (id)focusedMessages;
- (void)setFocusedMessages:(id)fp8;
- (int)appleScriptSortColumn;
- (void)setAppleScriptSortColumn:(int)fp8;
- (BOOL)isSortedAscending;
- (void)setIsSortedAscending:(BOOL)fp8;
- (BOOL)previewPaneVisible;
- (void)setPreviewPaneVisible:(BOOL)fp8;
- (id)visibleColumns;
- (void)setVisibleColumns:(id)fp8;
- (id)inbox;
- (id)outbox;
- (id)draftsMailbox;
- (id)sentMailbox;
- (id)trashMailbox;
- (id)junkMailbox;
- (void)setScriptingProperties:(id)fp8;
@end

