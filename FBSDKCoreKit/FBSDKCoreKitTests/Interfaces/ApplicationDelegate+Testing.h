// Copyright (c) 2014-present, Facebook, Inc. All rights reserved.
//
// You are hereby granted a non-exclusive, worldwide, royalty-free license to use,
// copy, modify, and distribute this software in source code or binary form for use
// in connection with the web services and APIs provided by Facebook.
//
// As with any software that integrates with the Facebook platform, your use of
// this software is subject to the Facebook Developer Principles and Policies
// [http://developers.facebook.com/policy/]. This copyright notice shall be
// included in all copies or substantial portions of the software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#import "FBSDKApplicationDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@protocol FBSDKSettingsLogging;
@protocol FBSDKAccessTokenProviding;
@protocol FBSDKEventLogging;
@protocol FBSDKFeatureChecking;
@protocol FBSDKNotificationObserving;
@protocol FBSDKApplicationLifecycleObserving;
@protocol FBSDKApplicationActivating;
@protocol FBSDKApplicationStateSetting;
@protocol FBSDKAppEventsConfiguring;

@interface FBSDKApplicationDelegate (Testing)

@property (nonatomic, assign) id<FBSDKNotificationObserving> notificationObserver;
@property (nonatomic, nullable) Class<FBSDKAccessTokenProviding, FBSDKAccessTokenSetting> tokenWallet;
@property (nonatomic, readonly, nonnull) id<FBSDKFeatureChecking> featureChecker;
@property (nonnull, nonatomic, readonly) id<FBSDKApplicationLifecycleObserving, FBSDKApplicationActivating, FBSDKApplicationStateSetting, FBSDKEventLogging> appEvents;

+ (void)resetHasInitializeBeenCalled
NS_SWIFT_NAME(reset());

- (instancetype)initWithNotificationObserver:(id<FBSDKNotificationObserving>)observer
                                 tokenWallet:(Class<FBSDKAccessTokenProviding, FBSDKAccessTokenSetting>)tokenWallet
                                    settings:(Class<FBSDKSettingsLogging>)settings
                              featureChecker:(id<FBSDKFeatureChecking>)featureChecker
                                   appEvents:(id<FBSDKAppEventsConfiguring, FBSDKApplicationLifecycleObserving, FBSDKApplicationActivating, FBSDKApplicationStateSetting, FBSDKEventLogging>)appEvents;
- (void)initializeSDKWithLaunchOptions:(NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions;
- (void)applicationDidEnterBackground:(NSNotification *)notification;
- (void)applicationDidBecomeActive:(NSNotification *)notification;
- (void)applicationWillResignActive:(NSNotification *)notification;
@end

NS_ASSUME_NONNULL_END
