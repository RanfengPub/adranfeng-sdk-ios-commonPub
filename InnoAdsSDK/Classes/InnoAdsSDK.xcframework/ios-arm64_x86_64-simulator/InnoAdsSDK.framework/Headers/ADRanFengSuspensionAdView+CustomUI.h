//
//  ADRanFengSuspensionAdView+CustomUI.h
//  InnoAdsSDK
//
//  Created by apple on 2025/12/10.
//

#import <InnoAdsSDK/ADRanFengSuspensionAdView.h>

NS_ASSUME_NONNULL_BEGIN

@interface ADRanFengSuspensionAdView ()

/**
 是否隐藏logo，默认不隐藏
 */
@property (nonatomic, assign) BOOL isHiddenLogo;

/**
 是否隐藏关闭按钮，默认不隐藏
 */
@property (nonatomic, assign) BOOL isHiddenClose;

/**
 自定义图片mode，默认UIViewContentModeScaleAspectFit（仅对非标生效）
 */
@property (nonatomic, assign) UIViewContentMode defaultPicContentMode;

/**
 自定义图片圆角，默认0（仅对非标生效）
 */
@property (nonatomic, assign) CGFloat defaultPicCornerRadius;

/**
 *  构造方法（自定义非标样式专用）
 *  详解：frame - Suspension 展示的位置和大小
 *               非标：设置视图宽度：0，高度：0即可，实际尺寸为100*120pt（设置有效defaultPicSize后可自定义大小）
 *               头像、单行文字链、多行文字链：设置自定义实际大小，demo参考尺寸依次为243*28pt、260*34pt、83*127pt
 *       postId - 广告位 ID
 *       suspensionType - 创新广告类型：非标、头像、单行文字链、多行文字链
 *       defaultPicSize - 自定义图片大小（仅对非标生效，下发图片素材为1:1）
 */
- (instancetype)initWithFrame:(CGRect)frame posId:(NSString *)posId suspensionType:(ADRanFengSuspensionType)suspensionType defaultPicSize:(CGSize)defaultPicSize;

@end

NS_ASSUME_NONNULL_END
