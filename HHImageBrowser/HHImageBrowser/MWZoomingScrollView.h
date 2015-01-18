//
//  ZoomingScrollView.h
//  MWPhotoBrowser
//
//  Created by Michael Waterfall on 14/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MWTapDetectingImageView.h"
#import "MWTapDetectingView.h"
#import "MWPhoto.h"

@class MWPhotoBrowser, MWPhoto;

@interface MWZoomingScrollView : UIScrollView <UIScrollViewDelegate, MWTapDetectingImageViewDelegate, MWTapDetectingViewDelegate> {

}

@property (nonatomic, assign) NSUInteger index;
@property (nonatomic, assign) id <MWPhoto> photo;
@property (nonatomic, retain) UIButton *selectedButton;

- (id)initWithPhotoBrowser:(MWPhotoBrowser *)browser;
- (void)displayImage;
- (void)displayImageFailure;
- (void)setMaxMinZoomScalesForCurrentBounds;
- (void)prepareForReuse;

@end
