#include "core/inst_handlers/zvfbfmin/RvzvfbfminInsts.hpp"

#include "core/inst_handlers/i/RviInsts.hpp"

#include "include/ActionTags.hpp"
#include "core/ActionGroup.hpp"
#include "core/PegasusState.hpp"
#include "core/PegasusInst.hpp"

namespace pegasus
{
    template <typename XLEN>
    void RvzvfbfminInsts::getInstHandlers(InstHandlers::InstHandlersMap & inst_handlers)
    {
        static_assert(std::is_same_v<XLEN, RV64> || std::is_same_v<XLEN, RV32>);

        (void)inst_handlers;
        inst_handlers.emplace(
            "vfncvtbf16.f.f.w", pegasus::Action::createAction<&RvzvfbfminInsts::fcvt_bf16_sHandler_<XLEN>,
                                                         RvzvfbfminInsts>(nullptr, "fcvt_bf16_s",
                                                                         ActionTags::EXECUTE_TAG));

        inst_handlers.emplace(
            "vfwcvtbf16.f.f.v", pegasus::Action::createAction<&RvzvfbfminInsts::fcvt_s_bf16Handler<XLEN>,
                                                         RvzvfbfminInsts>(nullptr, "fcvt_s_bf16",
                                                                         ActionTags::EXECUTE_TAG));
    }

    template void RvzvfbfminInsts::getInstHandlers<RV32>(InstHandlers::InstHandlersMap &);
    template void RvzvfbfminInsts::getInstHandlers<RV64>(InstHandlers::InstHandlersMap &);
} // namespace pegasus
