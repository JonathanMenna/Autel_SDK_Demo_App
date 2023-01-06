//
//  AUTELMission.h
//  AUTELSDK
//
//  Created by IOS on 16/2/29.
//  Copyright © 2016年 Autel. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  State of the task
 *
 *  任务的行动状态
 */
typedef NS_ENUM(uint8_t, AUTELMissionExecuteState ) {
    /**
     *  @brief Initializing task
     *
     *  正在初始化任务
     */
    AUTELMissionExecuteStateInitializing,
    /**
     *  @brief Performing task
     *
     *  正在执行任务
     */
    AUTELMissionExecuteStateMoving,
    /**
     *  @brief task paused. Aircraft hovering.
     *
     *  任务已暂停，飞行器正在悬停。
     */
    AUTELMissionExecuteStatePause,
    /**
     *  @brief task finished
     *
     *  任务已执行完毕
     */
    AUTELMissionExecuteStateFinish,
    /**
     *  @brief task state unknown
     *
     *  任务状态未知
     */
    AUTELMissionExecuteStateUnknown = 0xFF,
};

@class AUTELError;

/**
 *  The class is an base class representing the progress of an executing mission.
 *
 *  该类是当前任务的进度状态类的基类
 */
@interface AUTELMissionProgressStatus : NSObject

/**
 *  @brief This property describes the error which are generated by executing mission.
 *
 *  任务执行过程中发生的错误
 */
@property(nonatomic, strong) NSError *error;

/**
 *  @brief This method initial the object by corresponding error.
 *
 *  通过错误来初始化的方法
 *
 *  @param error object which is generated by executing mission.
 *
 *  任务执行过程中发生的错误
 *
 *  @return Returns a progress status object with error property
 *
 *  返回一个带有错误属性的进度状态对象
 */
- (instancetype)initWithError:(NSError *)error;

@end

@class AUTELMission;

/**
 *  Returns the progress status from 0.0 to 1.0
 *  返回一个0.0~1.0进度的block
 */
typedef void (^AUTELMissionProgressHandler)(float progress);

/**
 *  Download mission completion block.
 *  下载完智能飞行任务后的block回调
 *
 *  @param newMission New downloaded mission. 下载的智能飞行任务
 *  @param error      Error happens in downloading. 下载任务过程中发生的错误
 */
typedef void (^AUTELMissionDownloadCompletionBlock)(AUTELMission *newMission, NSError *error);


/** 
 *  The abstract base class of AUTELWaypointMission class, AUTELHotPointMission class and  AUTELFollowMeMission class.
 *
 *  智能飞行任务抽象基类 AUTELWaypointMission AUTELHotPointMission AUTELFollowMeMission 继承于该类
 */
@interface AUTELMission : NSObject

@end
