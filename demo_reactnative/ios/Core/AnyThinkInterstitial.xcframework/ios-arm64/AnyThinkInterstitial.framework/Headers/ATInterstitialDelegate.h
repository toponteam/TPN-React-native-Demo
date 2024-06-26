//
//  ATInterstitialDelegate.h
//  AnyThinkInterstitial
//
//  Created by Martin Lau on 21/09/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#ifndef ATInterstitialDelegate_h
#define ATInterstitialDelegate_h
#import <AnyThinkSDK/AnyThinkSDK.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kATInterstitialDelegateExtraNetworkIDKey; // Network Firm Id of Interstitial
extern NSString *const kATInterstitialDelegateExtraAdSourceIDKey; // ad source ID of Interstitial
extern NSString *const kATInterstitialDelegateExtraAdSourceIsHeaderBidding; // Whether the ad source is head bidding,1: yes, 2: no
extern NSString *const kATInterstitialDelegateExtraPrice; // Get Estimate eCPM
extern NSString *const kATInterstitialDelegateExtraPriority; // the sort of the current Interstitial ad source in WaterFall


@protocol ATInterstitialDelegate<ATAdLoadingDelegate>

/// Interstitial ad displayed successfully
- (void)interstitialDidShowForPlacementID:(NSString *)placementID
                                    extra:(NSDictionary *)extra;

/// Interstitial ad clicked
- (void)interstitialDidClickForPlacementID:(NSString *)placementID
                                     extra:(NSDictionary *)extra;

/// Interstitial ad closed
- (void)interstitialDidCloseForPlacementID:(NSString *)placementID
                                     extra:(NSDictionary *)extra;

@optional

/// Interstitial ad display failed
- (void)interstitialFailedToShowForPlacementID:(NSString *)placementID
                                         error:(NSError*)error
                                         extra:(NSDictionary *)extra;

/// Interstitial video ad playback start
- (void)interstitialDidStartPlayingVideoForPlacementID:(NSString *)placementID
                                                 extra:(NSDictionary *)extra;

/// Interstitial playback end
- (void)interstitialDidEndPlayingVideoForPlacementID:(NSString *)placementID
                                               extra:(NSDictionary *)extra;

/// Interstitial playback fail
- (void)interstitialDidFailToPlayVideoForPlacementID:(NSString *)placementID
                                               error:(NSError*)error
                                               extra:(NSDictionary *)extra;

/// Whether the click jump on the interstitial advertisement is in the form of Deeplink
/// currently only returns for TopOn Adx advertisements
- (void)interstitialDeepLinkOrJumpForPlacementID:(NSString *)placementID
                                           extra:(NSDictionary *)extra
                                          result:(BOOL)success;

/// Interstitial ad landing page closed
/// support network: [Baidu][GDT][KS][CSJ]
- (void)interstitialDidLPCloseForPlacementID:(NSString *)placementID
                                       extra:(NSDictionary *)extra;

@end

#endif /* ATInterstitialDelegate_h */

NS_ASSUME_NONNULL_END
