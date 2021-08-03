#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "uni_log.h"
#include "tuya_iot_sdk_api.h"

#include "user_iot_intf.h"

STATIC CHAR_T *__parse_config_file(CONST CHAR_T *filename)
{
    FILE *file = NULL;
    ty_cJSON *cfg = NULL;
    UINT_T length = 0;
    CHAR_T *content = NULL;
    UINT_T read_chars = 0;

    if (filename == NULL) {
        return NULL;
    }

    file = fopen(filename, "rb");
    if (file == NULL) {
        goto out;
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        goto out;
    }

    length = ftell(file);
    if (length < 0) {
        goto out;
    }

    if (fseek(file, 0, SEEK_SET) != 0) {
        goto out;
    }

    content = (CHAR_T *)malloc((UINT_T)length + SIZEOF (""));
    if (content == NULL) {
        goto out;
    }

    read_chars = fread(content, 1, (UINT_T)length, file);
    if (read_chars != length) {
        free(content);
        content = NULL;
        goto out;
    }
    content[read_chars] = '\0';

out:
    if (file != NULL) {
        fclose(file);
    }

    return content;
}

STATIC VOID __gw_reset_cb(GW_RESET_TYPE_E type)
{
    PR_DEBUG("gw reset callback");
    // TODO

    return;
}

STATIC VOID __gw_reboot_cb(VOID)
{
    PR_DEBUG("gw reboot callback");
    // TODO

    return;
}

STATIC VOID __gw_upgrade_cb(CONST FW_UG_S *fw)
{
    if (fw == NULL) {
        PR_ERR("invalid param");
        return;
    }

    PR_DEBUG("gw upgrade callback");
    PR_DEBUG("        tp: %d", fw->tp);
    PR_DEBUG("    fw_url: %s", fw->fw_url);
    PR_DEBUG("    sw_ver: %s", fw->sw_ver);
    PR_DEBUG("   fw_hmac: %s", fw->fw_hmac);
    PR_DEBUG(" file_size: %u", fw->file_size);

    return;
}

STATIC VOID __gw_active_stat_cb(GW_STATUS_E status)
{
    PR_DEBUG("gw active stat callback, registered: %d", status);

    return;
}
#if 0
STATIC VOID __gw_net_stat_cb(BOOL_T online)
{
    PR_DEBUG("gw net stat callback, online: %d", online);

    return;
}
#endif

int main(int argc, char **argv)
{
    OPERATE_RET op_ret         = OPRT_OK;
    ty_cJSON *root = NULL;
    CHAR_T *cfg_str = NULL;

    TY_GW_INFRA_CBS_S gw_cbs = {
        .gw_reset_cb       = __gw_reset_cb,
        .gw_reboot_cb      = __gw_reboot_cb,
        .gw_upgrade_cb     = __gw_upgrade_cb,
        .gw_active_stat_cb = __gw_active_stat_cb,
    };

    cfg_str = __parse_config_file("./config.json");
    if (cfg_str == NULL) {
        printf("parse json config failed\n");
        return 0;
    }

    op_ret = user_iot_init(cfg_str);
    if (op_ret != OPRT_OK) {
        PR_ERR("user_iot_init err: %d", op_ret);
        return op_ret;
    }

    op_ret = user_svc_init((VOID *)&gw_cbs);
    if (op_ret != OPRT_OK) {
        PR_ERR("user_svc_init err: %d", op_ret);
        return op_ret;
    }

    op_ret = user_svc_start(NULL);
    if (op_ret != OPRT_OK) {
        PR_ERR("user_svc_start err: %d", op_ret);
        return op_ret;
    }

    while (1) {
        sleep(10);
    }

    return 0;
}
