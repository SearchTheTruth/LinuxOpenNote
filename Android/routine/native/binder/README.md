binder使用例程:
1.创建一个service及对应client
2.service注册到servicemanager中
3.service维护一个文本列表
4.client可对该文本列表进行增删改查
5.service死亡时通知client进行响应.


目前问题:
疑似权限问题导致service启动后就died, 但已将selinux关闭
07-27 16:46:21.363   726   726 I thermal_repeater: [recvMdThermalInfo] ret=28, strLen=127,  2, 32767, -127, 0, 32767, 1
07-27 16:46:24.878   413   413 I SELinux : SELinux: Loaded service_contexts from:
07-27 16:46:24.879   413   413 I SELinux :     /vendor/etc/selinux/vndservice_contexts

07-27 16:46:24.879   413   413 I SELinux : avc:  received setenforce notice (enforcing=0)
07-27 16:46:24.880   413   413 I VendorServiceManager: service 'jianghao.testbinder' died

07-27 16:46:31.379   726   726 I thermal_repeater: [recvMdThermalInfo] ret=28, strLen=127,  2, 32767, -127, 0, 32767, 1
07-27 16:46:33.807  1315  1340 D AES     : AEEIOCTL_GET/SET_SF_STATE IOCTL,cmd= 1074294797, lParam=0. 
07-27 16:46:33.808  1315  1340 D AES     : AEEIOCTL_RT_MON_Kick IOCTL,cmd= 2147774474, lParam=300. 
07-27 16:46:36.971  1519  1659 I SecurityController: could not bind to KeyChainService
07-27 16:46:41.395   726   726 I thermal_repeater: [recvMdThermalInfo] ret=28, strLen=127,  2, 32767, -127, 0, 32767, 1
07-27 16:46:51.409   726   726 I chatty  : uid=1000(system) /vendor/bin/thermal identical 1 line
07-27 16:47:01.424   726   726 I thermal_repeater: [recvMdThermalInfo] ret=28, strLen=127,  2, 32767, -127, 0, 32767, 1
07-27 16:47:03.810  1315  1340 D AES     : AEEIOCTL_GET/SET_SF_STATE IOCTL,cmd= 1074294797, lParam=0. 
07-27 16:47:03.811  1315  1340 D AES     : AEEIOCTL_RT_MON_Kick IOCTL,cmd= 2147774474, lParam=300. 
07-27 16:47:05.344   413   413 I VendorServiceManager: service 'jianghao.testbinder' died
07-27 16:47:07.003  1519  1659 I SecurityController: could not bind to KeyChainService
07-27 16:47:11.435   726   726 I thermal_repeater: [recvMdThermalInfo] ret=28, strLen=127,  2, 32767, -127, 0, 32767, 1
07-27 16:47:16.608  1315  1481 W ActivityManager: Unable to start service Intent { cmp=com.miui.daemon/.performance.MiuiPerfService  } U=0: not found
07-27 16:47:16.609  1315  1481 V PerfShielderService: Miui performance: can't bind to com.miui.daemon.performance.MiuiPerfService
07-27 16:47:21.392  1519  1519 D KeyguardUpdateMonitor: received broadcast android.intent.action.BATTERY_CHANGED
07-27 16:47:21.450   726   726 I thermal_repeater: [recvMdThermalInfo] ret=28, strLen=127,  2, 32767, -127, 0, 32767, 1
07-27 16:47:31.466   726   726 I thermal_repeater: [recvMdThermalInfo] ret=28, strLen=127,  2, 32767, -127, 0, 32767, 1
07-27 16:47:33.813  1315  1340 D AES     : AEEIOCTL_GET/SET_SF_STATE IOCTL,cmd= 1074294797, lParam=0. 
07-27 16:47:33.814  1315  1340 D AES     : AEEIOCTL_RT_MON_Kick IOCTL,cmd= 2147774474, lParam=300. 
07-27 16:47:37.038  1519  1659 I SecurityController: could not bind to KeyChainService
07-27 16:47:41.482   726   726 I thermal_repeater: [recvMdThermalInfo] ret=28, strLen=127,  2, 32767, -127, 0, 32767, 1
07-27 16:47:48.032  2660  2660 I ServiceManager: Waiting for service 'jianghao.testbinder' on '/dev/vndbinder'...
07-27 16:47:51.390  2660  2660 I chatty  : uid=0(root) TestClient identical 33 lines
07-27 16:47:51.491  2660  2660 I ServiceManager: Waiting for service 'jianghao.testbinder' on '/dev/vndbinder'...
07-27 16:47:51.500   726   726 I thermal_repeater: [recvMdThermalInfo] ret=28, strLen=127,  2, 32767, -127, 0, 32767, 1
07-27 16:47:51.593  2660  2660 I ServiceManager: Waiting for service 'jianghao.testbinder' on '/dev/vndbinder'...
07-27 16:47:52.919  2660  2660 I chatty  : uid=0(root) TestClient identical 13 lines

07-27 16:47:53.021  2660  2660 I ServiceManager: Waiting for service 'jianghao.testbinder' on '/dev/vndbinder'...
07-27 16:47:53.121  2660  2660 W ServiceManager: Service jianghao.testbinder didn't start. Returning NULL

