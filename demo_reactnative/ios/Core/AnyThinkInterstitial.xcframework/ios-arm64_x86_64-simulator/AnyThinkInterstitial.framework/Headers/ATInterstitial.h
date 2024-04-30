//
//  ATInterstitial.h
//  AnyThinkInterstitial
//
//  Created by Martin Lau on 21/09/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AnyThinkSDK/AnyThinkSDK.h>

@class ATInterstitialCustomEvent;

NS_ASSUME_NONNULL_BEGIN

@interface ATInterstitial : ATAdObject

@property (nonatomic, strong) ATInterstitialCustomEvent *customEvent;
@property (nonatomic, assign) BOOL isNativeInterstitial;
@property (nonatomic, strong) NSDictionary *assets;
@property (nonatomic, strong) id <ATJoinAdProtocol>delegateObject;

@property (nonatomic, assign) NSInteger clickTag;

@end

NS_ASSUME_NONNULL_END
