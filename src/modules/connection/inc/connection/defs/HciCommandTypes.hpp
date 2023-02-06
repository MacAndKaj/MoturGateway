/*
 * Copyright (C) 2023 MacAndKaj - All Rights Reserved
*/

#ifndef CONNECTION_DEFS_HCICOMMANDTYPES_HPP_
#define CONNECTION_DEFS_HCICOMMANDTYPES_HPP_

#include <connection/defs/BtDeviceAddress.hpp>
#include <connection/defs/HciCommon.hpp>

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>

#include <variant>
#include <cstdint>
#include <map>

namespace connection::defs
{

enum HciCommandOgfName : std::uint8_t
{
    LinkControl = OGF_LINK_CTL,                 // 0x01
    LinkPolicy = OGF_LINK_POLICY,               // 0x02
    ControlAndBaseband = OGF_HOST_CTL,          // 0x03
    InformationalParameters = OGF_INFO_PARAM,   // 0x04
    StatusParameters = OGF_STATUS_PARAM,        // 0x05
    TestingCommands = OGF_TESTING_CMD           // 0x3e
};

/***********************************************************************************
 ***********************************************************************************
 *                      Link Control
 ***********************************************************************************
 ***********************************************************************************
 */
enum HciLinkControlOcfName : std::uint16_t
{
    HciInquiry = OCF_INQUIRY,                       // 0x01
    HciInquiryCancel = OCF_INQUIRY_CANCEL,          // 0x02
    HciPeriodicInquiryMode = OCF_PERIODIC_INQUIRY   // 0x03
    //TODO: end
};


/***********************************************************************************
 ***********************************************************************************
 *                      Link Policy
 ***********************************************************************************
 ***********************************************************************************
 */
enum HciLinkPolicyOcfName : std::uint16_t
{
    HciHoldMode = OCF_HOLD_MODE,    // 0x01
    HciSniffMode = OCF_SNIFF_MODE,  // 0x03
    //TODO: end
};


/***********************************************************************************
 ***********************************************************************************
 *                      Control and Baseband
 ***********************************************************************************
 ***********************************************************************************
 */
enum HciControlAndBasebandOcfName : std::uint16_t
{
    HciSetEventMask = OCF_SET_EVENT_MASK,   // 0x01
    HciReset = OCF_RESET,                   // 0x03
    HciSetEventFilter = OCF_SET_EVENT_FLT,  // 0x05
    HciReadLocalName = OCF_READ_LOCAL_NAME, // 0x14
    //TODO: end
};

/***********************************************************************************
 ***********************************************************************************
 *                      Informational Parameters
 ***********************************************************************************
 ***********************************************************************************
 */
enum HciInformationalParametersOcfName : std::uint16_t
{
    HciReadLocalVersionInfo = OCF_READ_LOCAL_VERSION,           // 0x01
    HciReadLocalSupportedCommands = OCF_READ_LOCAL_COMMANDS,    // 0x02
    HciReadLocalSupportedFeatures = OCF_READ_LOCAL_FEATURES,    // 0x03
    HciReadLocalExtendedFeatures = OCF_READ_LOCAL_EXT_FEATURES, // 0x04
    HciReadBufferSize = OCF_READ_BUFFER_SIZE,                   // 0x05
    HciReadBDAddr = OCF_READ_BD_ADDR,                           // 0x09
    HciReadDataBlockSize = OCF_READ_DATA_BLOCK_SIZE,            // 0x0A
};

// NO HciReadLocalVersionInfo Return Parameters
// NO HciReadLocalSupportedCommands Return Parameters
// NO HciReadLocalSupportedFeatures Return Parameters
// NO HciReadBufferSize Return Parameters
// NO HciReadBDAddr Return Parameters

struct HciReadBDAddrReturnParameters
{
    Status status;
    BtDeviceAddress bt_device_address;
};

/***********************************************************************************
 ***********************************************************************************
 *                      Status Parameters
 ***********************************************************************************
 ***********************************************************************************
 */
enum HciStatusParametersOcfName : std::uint16_t
{
    HciReadFailedContactCounter = OCF_READ_FAILED_CONTACT_COUNTER,      // 0x01
    HciResetFailedContactCounter = OCF_RESET_FAILED_CONTACT_COUNTER,    // 0x02
    //TODO: end
};

/***********************************************************************************
 ***********************************************************************************
 *                      Testing commands
 ***********************************************************************************
 ***********************************************************************************
 */
enum HciTestingCommandsOcfName : std::uint16_t
{
    HciReadLocalVersionInfoMask = OCF_SET_EVENT_MASK,   // 0x01
    //TODO: end
};


/***********************************************************************************
 ***********************************************************************************
 *                      SIZES
 ***********************************************************************************
 ***********************************************************************************
 */
const std::map<std::uint16_t, int> return_parameters_size_map = {
    {cmd_opcode_pack(InformationalParameters, HciReadLocalVersionInfo), READ_LOCAL_VERSION_RP_SIZE},
    {cmd_opcode_pack(InformationalParameters, HciReadLocalSupportedCommands), READ_LOCAL_COMMANDS_RP_SIZE},
    {cmd_opcode_pack(InformationalParameters, HciReadLocalSupportedFeatures), READ_LOCAL_FEATURES_RP_SIZE},
    {cmd_opcode_pack(InformationalParameters, HciReadLocalExtendedFeatures), READ_LOCAL_EXT_FEATURES_RP_SIZE},
    {cmd_opcode_pack(InformationalParameters, HciReadBufferSize), READ_BUFFER_SIZE_RP_SIZE},
    {cmd_opcode_pack(InformationalParameters, HciReadBDAddr), READ_BD_ADDR_RP_SIZE},
    {cmd_opcode_pack(InformationalParameters, HciReadDataBlockSize), sizeof(read_data_block_size_rp)},
};

const std::map<std::uint16_t, int> command_parameters_size_map = {
    {cmd_opcode_pack(InformationalParameters, HciReadLocalVersionInfo), 0},
    {cmd_opcode_pack(InformationalParameters, HciReadLocalSupportedCommands), 0},
    {cmd_opcode_pack(InformationalParameters, HciReadLocalSupportedFeatures), 0},
    {cmd_opcode_pack(InformationalParameters, HciReadLocalExtendedFeatures), READ_LOCAL_EXT_FEATURES_CP_SIZE},
    {cmd_opcode_pack(InformationalParameters, HciReadBufferSize), 0},
    {cmd_opcode_pack(InformationalParameters, HciReadBDAddr), 0},
    {cmd_opcode_pack(InformationalParameters, HciReadDataBlockSize), 0},
};

inline std::uint16_t opcode(std::uint8_t ogf, std::uint16_t ocf)
{
    return cmd_opcode_pack(ogf, ocf);
}

/***********************************************************************************
 ***********************************************************************************
 *                      VARIANTS
 ***********************************************************************************
 ***********************************************************************************
 */
typedef std::variant<
    std::monostate
> CommandParametersVariant;

typedef std::variant<
    std::monostate,
    HciReadBDAddrReturnParameters
> ReturnParametersVariant;

} // namespace connection::defs

#endif // CONNECTION_DEFS_HCICOMMANDTYPES_HPP_
