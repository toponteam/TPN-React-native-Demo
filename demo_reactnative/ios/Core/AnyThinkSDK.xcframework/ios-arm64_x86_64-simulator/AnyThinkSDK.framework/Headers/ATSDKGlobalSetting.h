//
//  ATSDKGlobalSetting.h
//  AnyThinkSDK
//
//  Created by Topon on 8/23/23.
//  Copyright © 2023 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ATSplashAdClickResultType) {
    ATSplashAdClickResultTypeDidCloseAd         = 1,  // 点击跳转后关闭开屏广告
    ATSplashAdClickResultTypePauseCountdown     = 2,  // 点击跳转后暂停倒计时，等开屏广告可见时继续倒计时
};

/// Debug values for testing geography.
typedef NS_ENUM(NSInteger, ATUMPDebugGeography) {
    ATUMPDebugGeographyDisabled = 0,  ///< Disable geography debugging.
    ATUMPDebugGeographyEEA = 1,       ///< Geography appears as in EEA for debug devices.
    ATUMPDebugGeographyNotEEA = 2,    ///< Geography appears as not in EEA for debug devices.
};

@interface ATSDKGlobalSetting : NSObject

+ (instancetype)sharedManager;

/// Splash Shake Text String, Only for DirectlyAd
@property (nonatomic, strong) NSString *directlySplashAdShakeTextString;

/// Splash CTA Button BackgroundColor, Only for DirectlyAd
@property (nonatomic, strong) UIColor *directlySplashAdCTAButtonBackgroundColor;

/// Whether to pause the countdown after clicking on the  Splash ad to jump, the default is NO, Only for TopOn ADX、DirectlyAd and Cross Promotion
@property (nonatomic, assign) BOOL clickToPauseCountdownSplashAd DEPRECATED_MSG_ATTRIBUTE("已废弃，请使用splashAdClickResultType");
/// 开屏广告点击跳转处理
@property (nonatomic, assign) ATSplashAdClickResultType splashAdClickResultType;

// ump test ids
@property (nonatomic, nullable,strong) NSArray<NSString *> *umpTestDeviceIdentifiers;
/// Debug geography.
@property (nonatomic, assign) ATUMPDebugGeography umpGeography;

@end

NS_ASSUME_NONNULL_END
