#pragma once

#include <libnuraft/nuraft.hxx>
#include <Coordination/InMemoryLogStore.h>
#include <Coordination/InMemoryStateManager.h>
#include <Coordination/NuKeeperStateMachine.h>
#include <Coordination/TestKeeperStorage.h>
#include <unordered_map>

namespace DB
{

class NuKeeperServer
{
private:
    int server_id;

    std::string hostname;

    int port;

    std::string endpoint;

    nuraft::ptr<NuKeeperStateMachine> state_machine;

    nuraft::ptr<nuraft::state_mgr> state_manager;

    nuraft::raft_launcher launcher;

    nuraft::ptr<nuraft::raft_server> raft_instance;

    using XIDToOp = std::unordered_map<Coordination::XID, Coordination::ZooKeeperResponsePtr>;

    using SessionIDOps = std::unordered_map<int64_t, XIDToOp>;

    SessionIDOps ops_mapping;

    TestKeeperStorage::ResponsesForSessions readZooKeeperResponses(nuraft::ptr<nuraft::buffer> & buffer);

public:
    NuKeeperServer(int server_id_, const std::string & hostname_, int port_);

    void startup();

    TestKeeperStorage::ResponsesForSessions putRequests(const TestKeeperStorage::RequestsForSessions & requests);

    int64_t getSessionID();

    void addServer(int server_id_, const std::string & server_uri, bool can_become_leader_, int32_t priority);

    bool isLeader() const;

    bool isLeaderAlive() const;

    bool waitForServer(int32_t server_id) const;
    void waitForServers(const std::vector<int32_t> & ids) const;
    void waitForCatchUp() const;

    TestKeeperStorage::ResponsesForSessions shutdown(const TestKeeperStorage::RequestsForSessions & expired_requests);
};

}
