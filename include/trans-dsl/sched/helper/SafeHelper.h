//
// Created by Darwin Yuan on 2020/6/15.
//

#ifndef TRANS_DSL_2_SAFEHELPER_H
#define TRANS_DSL_2_SAFEHELPER_H

#include <trans-dsl/sched/action/SchedSafe.h>
#include <trans-dsl/sched/helper/IsSchedAction.h>

TSL_NS_BEGIN

namespace details {
   template<typename T_ACTION, typename = void>
   struct Safe_;

   template<typename T_ACTION>
   struct Safe_<T_ACTION, IsSchedAction<T_ACTION>> : SchedSafe {
   private:
      IMPL_ROLE_WITH_VAR(SchedAction, action);
      T_ACTION action;
   };
}

TSL_NS_END

#define __safe(...) TSL_NS::details::Safe_<__VA_ARGS__>

#endif //TRANS_DSL_2_SAFEHELPER_H
