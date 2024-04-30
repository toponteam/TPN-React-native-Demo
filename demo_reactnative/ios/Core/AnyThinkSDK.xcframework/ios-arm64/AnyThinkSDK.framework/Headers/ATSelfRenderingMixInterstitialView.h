//
//  ATSelfRenderingMixInterstitialView.h
//  AnyThinkSDK
//
//  Created by GUO PENG on 2023/11/13.
//  Copyright © 2023 AnyThink. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ATSelfRenderingMixInterstitialView : UIView
/// 素材
@property (nonatomic, strong) NSDictionary *offerFodderDic;

@property (nonatomic, strong) UIImage *iconImage;
@property (nonatomic, strong) NSString *advertiserString;
@property (nonatomic, strong) NSString *titleString;
@property (nonatomic, strong) NSString *textString;
@property (nonatomic, strong) NSString *ctaString;
@property (nonatomic, strong) NSString *adWarnigString;
@property (nonatomic, strong) NSString *iconImageURLString;
@property (nonatomic, strong) NSString *mainImageURLString;
@property (nonatomic, strong) NSString *sponsorString;

// 获取媒体View
- (nullable UIView *)networkMediaView;

// 获取媒体自定义参数
- (nullable NSString *)getExtra;

// 设置关闭响应
- (void)registerClose:(nonnull UIView *)closeView;
// 设置点击响应
- (void)registerClickableViewArray:(nonnull NSArray<UIView *> *)registerClickViewArray;
// 关闭
- (void)close;

@end

NS_ASSUME_NONNULL_END
