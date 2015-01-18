//
//  MWPhotoBrowser_Private.h
//  MWPhotoBrowser
//
//  Created by Michael Waterfall on 08/10/2013.
//
//

#import <UIKit/UIKit.h>
#import "MBProgressHUD.h"
#import "MWZoomingScrollView.h"

// Declare private methods of browser
@interface MWPhotoBrowser () {
    
	// Data
    NSUInteger _photoCount;
	NSUInteger _currentPageIndex;
    NSUInteger _previousPageIndex;
    CGRect _previousLayoutBounds;
	NSUInteger _pageIndexBeforeRotation;
    
    // Misc
    BOOL _hasBelongedToViewController;
    BOOL _isVCBasedStatusBarAppearance;
    BOOL _statusBarShouldBeHidden;
    BOOL _displayActionButton;
    BOOL _leaveStatusBarAlone;
	BOOL _performingLayout;
	BOOL _rotating;
    BOOL _viewIsActive; // active as in it's in the view heirarchy
    BOOL _didSavePreviousStateOfNavBar;
    BOOL _skipNextPagingScrollViewPositioning;
    BOOL _viewHasAppearedInitially;
    CGPoint _currentGridContentOffset;
    
}

// Properties
@property (nonatomic,retain) UIActivityViewController *activityViewController;
@property (nonatomic,retain) NSMutableArray *photos;
@property (nonatomic,retain) NSArray *depreciatedPhotoData; // Depreciated
@property (nonatomic,retain) MBProgressHUD  *progressHUD;
@property (nonatomic,retain) UIScrollView *pagingScrollView;
@property (nonatomic,retain) NSMutableSet *visiblePages, *recycledPages;
// Layout
- (void)layoutVisiblePages;
- (void)performLayout;
- (BOOL)presentingViewControllerPrefersStatusBarHidden;


// Paging
- (void)tilePages;
- (BOOL)isDisplayingPageForIndex:(NSUInteger)index;
- (MWZoomingScrollView *)pageDisplayedAtIndex:(NSUInteger)index;
- (MWZoomingScrollView *)pageDisplayingPhoto:(id<MWPhoto>)photo;
- (MWZoomingScrollView *)dequeueRecycledPage;
- (void)configurePage:(MWZoomingScrollView *)page forIndex:(NSUInteger)index;
- (void)didStartViewingPageAtIndex:(NSUInteger)index;

// Frames
- (CGRect)frameForPagingScrollView;
- (CGRect)frameForPageAtIndex:(NSUInteger)index;
- (CGSize)contentSizeForPagingScrollView;
- (CGPoint)contentOffsetForPageAtIndex:(NSUInteger)index;
- (CGRect)frameForToolbarAtOrientation:(UIInterfaceOrientation)orientation;
- (CGRect)frameForSelectedButton:(UIButton *)selectedButton atIndex:(NSUInteger)index;

// Navigation
- (void)updateNavigation;
- (void)jumpToPageAtIndex:(NSUInteger)index animated:(BOOL)animated;
- (void)gotoPreviousPage;
- (void)gotoNextPage;

// Data
- (NSUInteger)numberOfPhotos;
- (UIImage *)imageForPhoto:(id<MWPhoto>)photo;
- (void)loadAdjacentPhotosIfNecessary:(id<MWPhoto>)photo;
- (void)releaseAllUnderlyingPhotos:(BOOL)preserveCurrent;

// Actions
- (void)savePhoto;

@end

