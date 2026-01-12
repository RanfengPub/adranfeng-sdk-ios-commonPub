//
//  ADRanFengSuspensionAdView.h
//  InnoAdsSDK
//
//  Created by 刘娟 on 2025/6/11.
//

#import <UIKit/UIKit.h>
#import <InnoAdsSDK/ADRanFengCommonDefine.h>
#import "ADRanFengAdInfoModel.h"

typedef NS_ENUM(NSUInteger, ADRanFengSuspensionType) {
    ADRanFengSuspensionTypeDefault = 0,     // 非标广告
    ADRanFengSuspensionTypeProfile = 1,     // 头像广告
    ADRanFengSuspensionTypeSingleText = 2,  // 单行文字链广告
    ADRanFengSuspensionTypeMultipleText = 3,// 多行文字链广告
};

NS_ASSUME_NONNULL_BEGIN
@class ADRanFengSuspensionAdView;

@protocol ADRanFengSuspensionAdViewDelegate <NSObject>

@optional
/**
 *  请求成功
 */
- (void)ranfengSuspensionSuccessLoad:(ADRanFengSuspensionAdView *)ranfengSuspensionView;

/**
 *  请求失败
 */
- (void)ranfengSuspensionViewFailedToLoadWithError:(NSError *)error;
/**
 *  展示回调
 */
- (void)ranfengSuspensionViewDidPresent:(ADRanFengSuspensionAdView *)ranfengSuspensionView;
/**
 *  曝光回调
 */
- (void)ranfengSuspensionViewWillExpose:(ADRanFengSuspensionAdView *)ranfengSuspensionView;

/**
 *  点击回调
 */
- (void)ranfengSuspensionViewClicked:(ADRanFengSuspensionAdView *)ranfengSuspensionView;

/**
 *  被用户关闭时调用
 */
- (void)ranfengSuspensionViewWillClose:(ADRanFengSuspensionAdView *)ranfengSuspensionView;

/**
 *  被用户关闭广告落地页调用
 */
- (void)ranfengSuspensionViewCloseLandingPage:(ADRanFengSuspensionAdView *)ranfengSuspensionView;


@end

@interface ADRanFengSuspensionAdView : UIView

/**
 *  委托
 */
@property (nonatomic ,weak) id<ADRanFengSuspensionAdViewDelegate>  delegate;

/*
 详解：当前ViewController[必传]
 */
@property (nonatomic ,weak) UIViewController  *viewController;

/**
 是否禁用刷新，默认不禁用
 */
@property (nonatomic, assign) BOOL isStopRefresh;

/**
 请设置刷新间隔
 */
@property (nonatomic, assign) NSInteger refreshTime;

/**
 是否播放，默认不播放，生效样式：头像广告、单行文字链
 */
@property (nonatomic, assign) BOOL isAutoPlay;

/**
 背景色，不设置使用默认值，生效样式：头像广告、单行文字链、多行文字链
 */
@property (nonatomic, strong) UIColor *bgViewBackgroundColor;

/**
 文字颜色，不设置使用默认值，生效样式：头像广告、单行文字链、多行文字链
 */
@property (nonatomic, strong) UIColor *textColor;

/**
 文字字体，不设置使用默认值，生效样式：头像广告、单行文字链、多行文字链
 */
@property (nonatomic, strong) UIFont *textFont;

/**
 *  构造方法（通用）
 *  详解：frame - Suspension 展示的位置和大小
 *               非标：设置视图宽度：0，高度：0即可，实际尺寸为100*120pt
 *               头像、单行文字链、多行文字链：设置自定义实际大小，demo参考尺寸依次为243*28pt、260*34pt、83*127pt
 *       postId - 广告位 ID
 *       suspensionType - 创新广告类型：非标、头像、单行文字链、多行文字链
 */
- (instancetype)initWithFrame:(CGRect)frame posId:(NSString *)posId suspensionType:(ADRanFengSuspensionType)suspensionType;

/**
 *  构造方法（非标样式专用，兼容旧版本、后续可能删除）
 *  详解：frame - Suspension 展示的位置和大小，这里设置视图宽度：0，高度：0即可，实际尺寸为100*120pt
 *       postId - 广告位 ID
 */
- (instancetype)initWithFrame:(CGRect)frame posId:(NSString *)posId;

/**
 *  开始请求广告
 */
- (void)loadRequest;

/**
 广告是否超时
 */
- (bool)isDataTimeout;

- (void)timerInvalidate;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，小于等于0表示广告请求失败或获取eCPM时机不正确(请于请求广告成功后获取)
*/
- (NSInteger)bidPrice;

/**
 返回广告的底价，单位：分
 
 @return 成功返回一个大于等于0的值，小于等于0表示广告请求失败或获取底价时机不正确(请于请求广告成功后获取)
*/
- (NSInteger)bidFloor;

/**
 *  竞赢上报，竞价广告位必须在展示前上报
 *  @param price 回传广告返回的出价，bidPrice(ecpm)，单位: 分
 */
- (void)sendWinNotificationWithPrice:(NSInteger)price;

/**
 *  竞败之后调用,
 *  @param reason 竞价失败原因
 *  @param winnerPirce 竟赢者价格，单位：分
 */
- (void)sendWinFailNotificationReason:(ADRanFengBiddingLossReason)reason winnerPirce:(NSInteger)winnerPirce;

/*
 获取广告相关信息，请一定在广告加载成功后获取
 */
- (ADRanFengAdInfoModel *)getInfoData;

/*
 手动开启播放，遇动画异常时调用，生效样式：头像广告、单行文字链
 */
- (void)textAutoPlay;

@end

NS_ASSUME_NONNULL_END
