//
//  ATNativeADView+Internal.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 03/05/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

/**
 * This file contains methods&properties implemented by ATNativeADView intented for internal use only.
 */
#import "ATNativeADView.h"

NS_ASSUME_NONNULL_BEGIN

@class ATNativeADCache;
@class ATNativeADCustomEvent;
@interface ATNativeADView (Internal)
/**
 * Designated initailizer
 * Loading delegate need to be passed because during the showing process, it's still posibile to encounter loading failure.
 */
//-(instancetype) initWithConfiguration:(ATNativeADConfiguration*)configuration currentOffer:(ATNativeADCache *)currentOffer placementID:(NSString*)placementID ;
/**
 * Use to bind the customEvent to the ad view.
 * In the current implementation, a instance of custom event will be create when the ad is to load and later acts as the delegate of the loading process, which will be release when the loading process finished; another will be create before the ad is to be shown and later acts as the delegate of the showing process.
 */
@property(nonatomic) ATNativeADCustomEvent *customEvent;

- (void)updateCallRendererStatus;

- (void)sendRenderFinishDa;

- (void)renderFinish;

//- (void)setWithConfiguration:(ATNativeADConfiguration*)configuration currentOffer:(ATNativeADCache *)currentOffer placementID:(NSString*)placementID selfRenderView:(UIView *)selfRenderView;

@end
NS_ASSUME_NONNULL_END
