//
//  ATSplash.h
//  AnyThinkSplash
//
//  Created by Martin Lau on 2018/12/20.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AnyThinkSDK/AnyThinkSDK.h>

@class ATSplashCustomEvent;

NS_ASSUME_NONNULL_BEGIN

@interface ATSplash : ATAdObject

//to do
// for ad which loads without a placement setting
@property(nonatomic) Class adapterClass;

@property(nonatomic, strong) ATSplashCustomEvent *customEvent;

@property(nonatomic) BOOL isNativeSplash;
@property(nonatomic) NSDictionary *assets;
@property(nonatomic) NSObject *delegateObject;

@end

NS_ASSUME_NONNULL_END
