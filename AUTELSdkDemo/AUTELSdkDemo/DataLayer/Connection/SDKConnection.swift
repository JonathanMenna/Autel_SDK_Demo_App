//
//  SDKConnection.swift
//  AUTELSdkDemo
//
//  Created by Devin on 2017/9/12.
//  Copyright © 2017年 AUTEL. All rights reserved.
//

import Foundation
import AUTELSDK


class SDKConnection: NSObject, AUTELAppManagerDelegate {
    
    static let shared = SDKConnection()
    
    /// 当前连接的设备，如果没有连接，则返回nil
    var connectedDevice: AUTELDevice? {
        get {
            return AUTELAppManager.connectedDevice()
        }
    }
    
    /// 私有初始化方法，防止外部调用
    private override init() {
        super.init()
        
    }
    
    
    func connect() -> Void {
        //appKey
        AUTELAppManager.registerApp("43d4c37a-b161-4861-b7b1-ba1c78cda6d7", with: self)
    }
    
    // MARK: - AUTELAppManagerDelegate
    
    func appManagerDidConnectedDeviceChanged(_ newDevice: AUTELDevice) {
        DroneConnection.shared.connect(newDevice)
    }
    
    func appManagerDidRegisterWithError(_ error: Error?) {
        if let _ = error {
            print("app register failure")
        } else {
            print("app register success")
        }
        
    }
    
}
