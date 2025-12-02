#pragma once

#include "core/ActionGroup.hpp"
#include "common.hpp"

#include "sparta/simulation/ParameterSet.hpp"
#include "sparta/simulation/TreeNode.hpp"
#include "sparta/simulation/Unit.hpp"


struct request;
typedef struct request request;
class Unit;


namespace pegasus
{
    class PegasusState;

    class UnifiedBuffer : public sparta::Unit
    {
        public:
            static constexpr char name[] = "UnifiedBuffer";
            using base_type = UnifiedBuffer;

            class FetchParameters : public sparta::ParameterSet
            {
            public:
                FetchParameters(sparta::TreeNode* node) : sparta::ParameterSet(node) {}
            };

            UnifiedBuffer(float buffer_size);
            
            bool IsMainMemory() {return is_main_memory;}

            ActionGroup* getActionGroup() { return &buffer_action_group_; }
        
        private:
            Action::ItrType execute_(pegasus::PegasusState* state, Action::ItrType action_it);

            ActionGroup buffer_action_group_{"UnifiedBuffer"};
    } 
}


class UnifiedBuffer: public Unit {
public:
    UnifiedBuffer(float buffer_size);
    ~UnifiedBuffer();
    void Cycle();
    
    bool IsMainMemory() {return is_main_memory;}
    // connected to Matrix Multiply Unit
    std::vector<request> *GetSenderQueue() {return sender_queue;}
    // connected to DRAM
    std::vector<request> *GetServedQueue() {return served_queue;}
    std::vector<request> *GetWaitingQueue() {return waiting_queue;}
    std::vector<request> *GetRequestQueue() {return request_queue;}

    float GetCapacity() {return capacity;}
private:
    float capacity;         // size of buffer
    bool is_main_memory;

    // connected to Matrix Multiply Unit
    std::vector<request> *sender_queue;
    // connected to DRAM
    std::vector<request> *served_queue;
    std::vector<request> *waiting_queue;
    std::vector<request> *request_queue;
};
