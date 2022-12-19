/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
*/
#include <connection/hci/SubscriptionsStorage.hpp>

#include <IConnectionContextMock.hpp>

#include <ConnectionTestBase.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace connection::hci
{

class SubscriptionsStorageTests : public ::testing::Test, public test::ConnectionTestBase
{
public:
    std::unique_ptr<ISubscriptionsStorage> createSut()
    {
        return std::make_unique<SubscriptionsStorage>(test::ConnectionTestBase::getContext().getLogger());
    }
};

TEST_F(SubscriptionsStorageTests, BasicSuccessfullCase)
{
    auto sut = createSut();
    bool called = false;
    auto callback = [&called](const defs::HciEvent&)
    {
        called = true;
    };
    auto SubscriptionGuard = sut->subscribe(defs::HciEventName::ConnectionComplete, callback);

    defs::HciEvent event{};
    event.name = defs::HciEventName::ConnectionComplete;
    sut->notifyAll(event);

    EXPECT_TRUE(called);
}

} // namespace connection::hci
