//
//  DIYCam.h
//  cam
//
//  Created by Andrew Sliwinski on 7/5/12.
//  Copyright (c) 2012 DIY, Co. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

#import "DIYAV.h"
#import "DIYCamUtilities.h"
#import "DIYCamFileOperation.h"
#import "DIYCamLibraryImageOperation.h"
#import "DIYCamLibraryVideoOperation.h"

//

@class DIYCam;

@protocol DIYCamDelegate <NSObject>
@required
- (void)camReady:(DIYCam *)cam;
- (void)camDidFail:(DIYCam *)cam withError:(NSError *)error;

- (void)camModeWillChange:(DIYCam *)cam mode:(DIYAVMode)mode;
- (void)camModeDidChange:(DIYCam *)cam mode:(DIYAVMode)mode;

- (void)camCaptureStarted:(DIYCam *)cam;
- (void)camCaptureStopped:(DIYCam *)cam;
- (void)camCaptureProcessing:(DIYCam *)cam;
- (void)camCaptureComplete:(DIYCam *)cam withAsset:(NSDictionary *)asset;
@end

//

@interface DIYCam : UIView <DIYAVDelegate>

@property (weak) id<DIYCamDelegate> delegate;

#pragma mark - Status
- (BOOL)getRecordingStatus;
- (void)stopSession;
- (void)startSession;
- (DIYAVMode)getCamMode;
- (void)setCamMode:(DIYAVMode)mode;

#pragma mark - Capture
- (void)capturePhoto;
- (void)captureVideoStart;
- (void)captureVideoStop;

@end