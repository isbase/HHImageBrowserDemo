//
//  HHPhotoBrowser.m
//  HHImageBrowser
//
//  Created by Today on 15-1-12.
//  Copyright (c) 2015年 Today. All rights reserved.
//

#import "HHPhotoBrowser.h"

@interface HHPhotoBrowser ()
{
    UIScrollView        *_pagingScrollView;
    NSUInteger          _photoCount;
    NSInteger           _currentPageIndex;
    NSMutableArray      *_photos;
}
@end

@implementation HHPhotoBrowser

- (instancetype)init
{
    self = [super init];
    if (self) {
    
    }
    return self;
}

-(void)initialize
{
    _photoCount = NSNotFound;
    _currentPageIndex = 0;
    _photos     = [[NSMutableArray alloc] init];
}

-(void)viewDidLoad
{
    [super viewDidLoad];
    
    _pagingScrollView = [[UIScrollView alloc] initWithFrame:self.view.frame];
    _pagingScrollView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    _pagingScrollView.pagingEnabled = YES;
    _pagingScrollView.delegate = self;
    _pagingScrollView.showsHorizontalScrollIndicator = NO;
    _pagingScrollView.showsVerticalScrollIndicator = NO;
    _pagingScrollView.backgroundColor = [UIColor blackColor];
    [self.view addSubview:_pagingScrollView];
}

- (CGRect)frameForPageAtIndex:(NSUInteger)index {
    CGRect bounds = _pagingScrollView.bounds;
    CGRect pageFrame = bounds;
    return CGRectIntegral(pageFrame);
}

- (CGSize)contentSizeForPagingScrollView {
    // We have to use the paging scroll view's bounds to calculate the contentSize, for the same reason outlined above.
    CGRect bounds = _pagingScrollView.bounds;
    return CGSizeMake(bounds.size.width * [self numberOfPhotos], bounds.size.height);
}

-(NSInteger)numberOfPhotos
{
    _photoCount = _photos.count;
    if (_photoCount == NSNotFound) _photoCount = 0;
    return _photoCount;
}

- (CGPoint)contentOffsetForPageAtIndex:(NSUInteger)index {
    CGFloat pageWidth = _pagingScrollView.bounds.size.width;
    CGFloat newOffset = index * pageWidth;
    return CGPointMake(newOffset, 0);
}

-(void)scrollViewDidScroll:(UIScrollView *)scrollView
{
    // Tile pages
    [self tilePages];
    
    // Calculate current page
    CGRect visibleBounds = _pagingScrollView.bounds;
    NSInteger index = (NSInteger)(floorf(CGRectGetMidX(visibleBounds) / CGRectGetWidth(visibleBounds)));
    if (index < 0) index = 0;
    if (index > [self numberOfPhotos] - 1) index = [self numberOfPhotos] - 1;
    NSUInteger previousCurrentPage = _currentPageIndex;
    _currentPageIndex = index;
    if (_currentPageIndex != previousCurrentPage) {
        //[self didStartViewingPageAtIndex:index];
    }
}


@end
