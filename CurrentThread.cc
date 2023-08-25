#include "CurrentThread.h"

namespace CurrentThread
{
    //线程之间共享变量，__使线程有各自的变量
    __thread int t_cachedTid = 0;   

    void cacheTid()
    {
        if (t_cachedTid == 0)
        {
            // 通过linux系统调用，获取当前线程的tid值
            t_cachedTid = static_cast<pid_t>(::syscall(SYS_gettid));
        }
    }
}