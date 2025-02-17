/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2021 MediaTek Inc.
 */

#ifndef __MT6886_PWR_CTRL_H__
#define __MT6886_PWR_CTRL_H__

/* SPM_WAKEUP_MISC */
#define WAKE_MISC_SRCLKEN_RC_ERR_INT	 (1U << 0)
#define WAKE_MISC_SPM_TIMEOUT_WAKEUP_0	 (1U << 1)
#define WAKE_MISC_SPM_TIMEOUT_WAKEUP_1	 (1U << 2)
#define WAKE_MISC_SPM_TIMEOUT_WAKEUP_2	 (1U << 3)
#define WAKE_MISC_DVFSRC_IRQ			 (1U << 4)
#define WAKE_MISC_TWAM_IRQ_B			 (1U << 5)
#define WAKE_MISC_SPM_ACK_CHK_WAKEUP_0   (1U << 6)
#define WAKE_MISC_SPM_ACK_CHK_WAKEUP_1	 (1U << 7)
#define WAKE_MISC_SPM_ACK_CHK_WAKEUP_2	 (1U << 8)
#define WAKE_MISC_SPM_ACK_CHK_WAKEUP_3	 (1U << 9)
#define WAKE_MISC_SPM_ACK_CHK_WAKEUP_ALL (1U << 10)
#define WAKE_MISC_VLP_BUS_TIMEOUT_IRQ	 (1U << 11)
#define WAKE_MISC_PCM_TIMER_EVENT		 (1U << 16)
#define WAKE_MISC_REG_CPU_WAKEUP		 (1U << 17)
#define WAKE_MISC_PMIC_EINT_OUT			 ((1U << 19) | (1U << 20))
#define WAKE_MISC_PMSR_IRQ_B_SET0		 (1U << 22)
#define WAKE_MISC_PMSR_IRQ_B_SET1		 (1U << 23)
#define WAKE_MISC_PMSR_IRQ_B_SET2		 (1U << 24)
#define WAKE_MISC_PMIC_IRQ_ACK			 (1U << 30)
#define WAKE_MISC_PMIC_SCP_IRQ			 (1U << 31)

struct pwr_ctrl {
	/* for SPM */
	u32 pcm_flags;
	u32 pcm_flags_cust;	/* can override pcm_flags */
	u32 pcm_flags_cust_set;	/* set bit of pcm_flags, after pcm_flags_cust */
	u32 pcm_flags_cust_clr;	/* clr bit of pcm_flags, after pcm_flags_cust */
	u32 pcm_flags1;
	u32 pcm_flags1_cust;	/* can override pcm_flags1 */
	u32 pcm_flags1_cust_set;	/* set bit of pcm_flags1, after pcm_flags1_cust */
	u32 pcm_flags1_cust_clr;	/* clr bit of pcm_flags1, after pcm_flags1_cust */
	u32 timer_val;		/* @ 1T 32K */
	u32 timer_val_cust;	/* @ 1T 32K, can override timer_val */
	u32 timer_val_ramp_en;		/* stress for dpidle */
	u32 timer_val_ramp_en_sec;	/* stress for suspend */
	u32 wake_src;
	u32 wake_src_cust;	/* can override wake_src */
	u32 wakelock_timer_val;
	u8 wdt_disable;		/* disable wdt in suspend */

	/* Auto-gen Start */

	/* SPM_SRC_REQ */
	u8 reg_spm_adsp_mailbox_req;
	u8 reg_spm_apsrc_req;
	u8 reg_spm_ddren_req;
	u8 reg_spm_dvfs_req;
	u8 reg_spm_emi_req;
	u8 reg_spm_f26m_req;
	u8 reg_spm_infra_req;
	u8 reg_spm_pmic_req;
	u8 reg_spm_scp_mailbox_req;
	u8 reg_spm_sspm_mailbox_req;
	u8 reg_spm_sw_mailbox_req;
	u8 reg_spm_vcore_req;
	u8 reg_spm_vrf18_req;
	u8 adsp_mailbox_state;
	u8 apsrc_state;
	u8 ddren_state;
	u8 dvfs_state;
	u8 emi_state;
	u8 f26m_state;
	u8 infra_state;
	u8 pmic_state;
	u8 scp_mailbox_state;
	u8 sspm_mailbox_state;
	u8 sw_mailbox_state;
	u8 vcore_state;
	u8 vrf18_state;

	/* SPM_SRC_MASK_0 */
	u8 reg_peri_ddren_req_mask_b;
	u8 reg_apu_ddren_req_mask_b;
	u8 reg_audio_dsp_ddren_req_mask_b;
	u8 reg_cam_ddren_req_mask_b;
	u8 reg_ifr_ddren_req_mask_b;
	u8 reg_conn_ddren_req_mask_b;
	u8 reg_mcupm_ddren_req_mask_b;
	u8 reg_disp0_ddren_req_mask_b;
	u8 reg_gce_ddren_req_mask_b;
	u8 reg_gpueb_ddren_req_mask_b;
	u8 reg_img_ddren_req_mask_b;
	u8 reg_infrasys_ddren_req_mask_b;
	u8 reg_md_ddren_req_mask_b;
	u8 reg_mdp0_ddren_req_mask_b;
	u8 reg_mm_proc_ddren_req_mask_b;
	u8 reg_msdc1_ddren_req_mask_b;
	u8 reg_scp_ddren_req_mask_b;
	u8 reg_sspm_ddren_req_mask_b;
	u8 reg_ssusb0_ddren_req_mask_b;
	u8 reg_ufs_ddren_req_mask_b;
	u8 reg_vdec_ddren_req_mask_b;
	u8 reg_venc_ddren_req_mask_b;
	u8 reg_mmsys_ddren_req_mask_b;
	u8 reg_cg_check_ddren_req_mask_b;

	/* SPM_SRC_MASK_1 */
	u8 reg_peri_apsrc_req_mask_b;
	u8 reg_apu_apsrc_req_mask_b;
	u8 reg_audio_dsp_apsrc_req_mask_b;
	u8 reg_cam_apsrc_req_mask_b;
	u8 reg_ifr_apsrc_req_mask_b;
	u8 reg_conn_apsrc_req_mask_b;
	u8 reg_mcupm_apsrc_req_mask_b;
	u8 reg_disp0_apsrc_req_mask_b;
	u8 reg_dpm_apsrc_req_mask_b;
	u8 reg_gce_apsrc_req_mask_b;
	u8 reg_gpueb_apsrc_req_mask_b;
	u8 reg_img_apsrc_req_mask_b;
	u8 reg_infrasys_apsrc_req_mask_b;
	u8 reg_md_apsrc_req_mask_b;
	u8 reg_mdp0_apsrc_req_mask_b;
	u8 reg_mm_proc_apsrc_req_mask_b;
	u8 reg_msdc1_apsrc_req_mask_b;
	u8 reg_scp_apsrc_req_mask_b;
	u8 reg_sspm_apsrc_req_mask_b;
	u8 reg_ssusb0_apsrc_req_mask_b;
	u8 reg_ufs_apsrc_req_mask_b;
	u8 reg_vdec_apsrc_req_mask_b;
	u8 reg_venc_apsrc_req_mask_b;
	u8 reg_mmsys_apsrc_req_mask_b;
	u8 reg_cg_check_apsrc_req_mask_b;

	/* SPM_SRC_MASK_2 */
	u8 reg_peri_vrf18_req_mask_b;
	u8 reg_apu_vrf18_req_mask_b;
	u8 reg_audio_dsp_vrf18_req_mask_b;
	u8 reg_ifr_vrf18_req_mask_b;
	u8 reg_conn_vrf18_req_mask_b;
	u8 reg_mcupm_vrf18_req_mask_b;
	u8 reg_dpm_vrf18_req_mask_b;
	u8 reg_gce_vrf18_req_mask_b;
	u8 reg_gpueb_vrf18_req_mask_b;
	u8 reg_md_vrf18_req_mask_b;
	u8 reg_mm_proc_vrf18_req_mask_b;
	u8 reg_msdc1_vrf18_req_mask_b;
	u8 reg_scp_vrf18_req_mask_b;
	u8 reg_sspm_vrf18_req_mask_b;
	u8 reg_ssusb0_vrf18_req_mask_b;
	u8 reg_ufs_vrf18_req_mask_b;
	u8 reg_mmsys_vrf18_req_mask_b;
	u8 reg_cg_check_vrf18_req_mask_b;

	/* SPM_SRC_MASK_3 */
	u8 reg_peri_infra_req_mask_b;
	u8 reg_apu_infra_req_mask_b;
	u8 reg_audio_dsp_infra_req_mask_b;
	u8 reg_cam_infra_req_mask_b;
	u8 reg_ifr_infra_req_mask_b;
	u8 reg_conn_infra_req_mask_b;
	u8 reg_mcupm_infra_req_mask_b;
	u8 reg_dpm_infra_req_mask_b;
	u8 reg_gce_infra_req_mask_b;
	u8 reg_gpueb_infra_req_mask_b;
	u8 reg_md_infra_req_mask_b;
	u8 reg_mm_proc_infra_req_mask_b;
	u8 reg_msdc1_infra_req_mask_b;
	u8 reg_scp_infra_req_mask_b;
	u8 reg_srcclkeni_infra_req_mask_b;
	u8 reg_sspm_infra_req_mask_b;
	u8 reg_ssusb0_infra_req_mask_b;
	u8 reg_ufs_infra_req_mask_b;

	/* SPM_SRC_MASK_4 */
	u8 reg_peri_srcclkena_mask_b;
	u8 reg_apu_srcclkena_mask_b;
	u8 reg_audio_dsp_srcclkena_mask_b;
	u8 reg_ifr_srcclkena_mask_b;
	u8 reg_conn_srcclkena_mask_b;
	u8 reg_conn_srcclkenb_mask_b;
	u8 reg_mcupm_srcclkena_mask_b;
	u8 reg_gpueb_srcclkena_mask_b;
	u8 reg_md_srcclkena_mask_b;
	u8 reg_md_srcclkena1_mask_b;
	u8 reg_mm_proc_srcclkena_mask_b;
	u8 reg_msdc1_srcclkena_mask_b;
	u8 reg_scp_srcclkena_mask_b;
	u8 reg_srcclkeni_srcclkena_mask_b;
	u8 reg_sspm_srcclkena_mask_b;
	u8 reg_ssusb0_srcclkena_mask_b;
	u8 reg_ufs_srcclkena_mask_b;
	u8 reg_cg_check_srcclkena_mask_b;

	/* SPM_SRC_MASK_5 */
	u8 reg_ifr_vcore_req_mask_b;
	u8 reg_conn_vcore_req_mask_b;
	u8 reg_md_vcore_req_mask_b;
	u8 reg_cg_check_vcore_req_mask_b;

	/* SPM_SRC_MASK_6 */
	u8 reg_peri_emi_req_mask_b;
	u8 reg_apu_emi_req_mask_b;
	u8 reg_audio_dsp_emi_req_mask_b;
	u8 reg_cam_emi_req_mask_b;
	u8 reg_ifr_emi_req_mask_b;
	u8 reg_conn_emi_req_mask_b;
	u8 reg_mcupm_emi_req_mask_b;
	u8 reg_disp0_emi_req_mask_b;
	u8 reg_dpm_emi_req_mask_b;
	u8 reg_gce_emi_req_mask_b;
	u8 reg_gpueb_emi_req_mask_b;
	u8 reg_img_emi_req_mask_b;
	u8 reg_infrasys_emi_req_mask_b;
	u8 reg_md_emi_req_mask_b;
	u8 reg_mdp0_emi_req_mask_b;
	u8 reg_mm_proc_emi_req_mask_b;
	u8 reg_msdc1_emi_req_mask_b;
	u8 reg_scp_emi_req_mask_b;
	u8 reg_sspm_emi_req_mask_b;
	u8 reg_ssusb0_emi_req_mask_b;
	u8 reg_ufs_emi_req_mask_b;
	u8 reg_vdec_emi_req_mask_b;
	u8 reg_venc_emi_req_mask_b;
	u8 reg_mmsys_emi_req_mask_b;
	u8 reg_cg_check_emi_req_mask_b;

	/* SPM_SRC_MASK_7 */
	u8 reg_peri_pmic_req_mask_b;
	u8 reg_apu_pmic_req_mask_b;
	u8 reg_audio_dsp_pmic_req_mask_b;
	u8 reg_conn_pmic_req_mask_b;
	u8 reg_mcupm_pmic_req_mask_b;
	u8 reg_gpueb_pmic_req_mask_b;
	u8 reg_md_pmic_req_mask_b;
	u8 reg_mm_proc_pmic_req_mask_b;
	u8 reg_msdc1_pmic_req_mask_b;
	u8 reg_scp_pmic_req_mask_b;
	u8 reg_srcclkeni_pmic_req_mask_b;
	u8 reg_sspm_pmic_req_mask_b;
	u8 reg_ssusb0_pmic_req_mask_b;
	u8 reg_ufs_pmic_req_mask_b;
	u8 reg_cg_check_pmic_req_mask_b;

	/* SPM_SRC_MASK_8 */
	u8 reg_mcusys_apsrc_req_mask_b;
	u8 reg_mcusys_ddren_req_mask_b;
	u8 reg_mcusys_emi_req_mask_b;
	u8 reg_dvfsrc_level_req_mask_b;

	/* SPM_EVENT_CON_MISC */
	u8 reg_srcclken_fast_resp;
	u8 reg_csyspwrup_ack_mask;

	/* Auto-gen End */

	/* INFRA_DDREN_REQ_MASK */
	u32 reg_infra_merge_ccif_ddren_req_mask_b;
	u8 reg_infra_merge_dpmaif_ddren_req_mask_b;
	u8 reg_infra_merge_ipic_ddren_req_mask_b;

	/* INFRA_APSRC_REQ_MASK */
	u32 reg_infra_merge_ccif_apsrc_req_mask_b;
	u8 reg_infra_merge_dpmaif_apsrc_req_mask_b;
	u8 reg_infra_merge_ipic_apsrc_req_mask_b;

	/* INFRA_VRF18_REQ_MASK */
	u32 reg_infra_merge_ccif_vrf18_req_mask_b;
	u8 reg_infra_merge_dpmaif_vrf18_req_mask_b;
	u8 reg_infra_merge_ipic_vrf18_req_mask_b;

	/* INFRA_INFRA_REQ_MASK */
	u32 reg_infra_merge_ccif_infra_req_mask_b;
	u8 reg_infra_merge_dpmaif_infra_req_mask_b;
	u8 reg_infra_merge_ipic_infra_req_mask_b;

	/* INFRA_26M_REQ_MASK */
	u32 reg_infra_merge_ccif_srcclkena_req_mask_b;
	u8 reg_infra_merge_dpmaif_srcclkena_req_mask_b;
	u8 reg_infra_merge_ipic_srcclkena_req_mask_b;

	/* INFRA_VCORE_REQ_MASK */
	u32 reg_infra_merge_ccif_vcore_req_mask_b;
	u8 reg_infra_merge_dpmaif_vcore_req_mask_b;
	u8 reg_infra_merge_ipic_vcore_req_mask_b;

	/* PERI_SEC_RSV_0 for afe, msdc, ssusb MASK */
	u8 reg_peri_merge_afe_srcclkena_req_mask_b;
	u8 reg_peri_merge_msdc_srcclkena_req_mask_b;
	u8 reg_peri_merge_ssusb_srcclkena_req_mask_b;
	u8 reg_peri_merge_afe_infra_req_mask_b;
	u8 reg_peri_merge_msdc_infra_req_mask_b;
	u8 reg_peri_merge_ssusb_infra_req_mask_b;
	u8 reg_peri_merge_afe_vrf18_req_mask_b;
	u8 reg_peri_merge_msdc_vrf18_req_mask_b;
	u8 reg_peri_merge_ssusb_vrf18_req_mask_b;
	u8 reg_peri_merge_afe_apsrc_ddren_req_mask_b;
	u8 reg_peri_merge_msdc_apsrc_ddren_req_mask_b;
	u8 reg_peri_merge_ssusb_apsrc_ddren_req_mask_b;

	/* SPM_WAKEUP_EVENT_MASK */
	u32 reg_wakeup_event_mask;

	/* SPM_WAKEUP_EVENT_EXT_MASK */
	u32 reg_ext_wakeup_event_mask;

	/* Auto-gen End */
};

/* code gen by spm_pwr_ctrl_atf.pl, need struct pwr_ctrl */
enum pwr_ctrl_enum {
	PW_PCM_FLAGS,
	PW_PCM_FLAGS_CUST,
	PW_PCM_FLAGS_CUST_SET,
	PW_PCM_FLAGS_CUST_CLR,
	PW_PCM_FLAGS1,
	PW_PCM_FLAGS1_CUST,
	PW_PCM_FLAGS1_CUST_SET,
	PW_PCM_FLAGS1_CUST_CLR,
	PW_TIMER_VAL,
	PW_TIMER_VAL_CUST,
	PW_TIMER_VAL_RAMP_EN,
	PW_TIMER_VAL_RAMP_EN_SEC,
	PW_WAKE_SRC,
	PW_WAKE_SRC_CUST,
	PW_WAKELOCK_TIMER_VAL,
	PW_WDT_DISABLE,

	/* AUTO-GEN START */

	/* SPM_SRC_REQ */
	PW_REG_SPM_ADSP_MAILBOX_REQ,
	PW_REG_SPM_APSRC_REQ,
	PW_REG_SPM_DDREN_REQ,
	PW_REG_SPM_DVFS_REQ,
	PW_REG_SPM_EMI_REQ,
	PW_REG_SPM_F26M_REQ,
	PW_REG_SPM_INFRA_REQ,
	PW_REG_SPM_PMIC_REQ,
	PW_REG_SPM_SCP_MAILBOX_REQ,
	PW_REG_SPM_SSPM_MAILBOX_REQ,
	PW_REG_SPM_SW_MAILBOX_REQ,
	PW_REG_SPM_VCORE_REQ,
	PW_REG_SPM_VRF18_REQ,
	PW_ADSP_MAILBOX_STATE,
	PW_APSRC_STATE,
	PW_DDREN_STATE,
	PW_DVFS_STATE,
	PW_EMI_STATE,
	PW_F26M_STATE,
	PW_INFRA_STATE,
	PW_PMIC_STATE,
	PW_SCP_MAILBOX_STATE,
	PW_SSPM_MAILBOX_STATE,
	PW_SW_MAILBOX_STATE,
	PW_VCORE_STATE,
	PW_VRF18_STATE,

	/* SPM_SRC_MASK_0 */
	PW_REG_PERI_DDREN_REQ_MASK_B,
	PW_REG_APU_DDREN_REQ_MASK_B,
	PW_REG_AUDIO_DSP_DDREN_REQ_MASK_B,
	PW_REG_CAM_DDREN_REQ_MASK_B,
	PW_REG_IFR_DDREN_REQ_MASK_B,
	PW_REG_CONN_DDREN_REQ_MASK_B,
	PW_REG_MCUPM_DDREN_REQ_MASK_B,
	PW_REG_DISP0_DDREN_REQ_MASK_B,
	PW_REG_GCE_DDREN_REQ_MASK_B,
	PW_REG_GPUEB_DDREN_REQ_MASK_B,
	PW_REG_IMG_DDREN_REQ_MASK_B,
	PW_REG_INFRASYS_DDREN_REQ_MASK_B,
	PW_REG_MD_DDREN_REQ_MASK_B,
	PW_REG_MDP0_DDREN_REQ_MASK_B,
	PW_REG_MM_PROC_DDREN_REQ_MASK_B,
	PW_REG_MSDC1_DDREN_REQ_MASK_B,
	PW_REG_SCP_DDREN_REQ_MASK_B,
	PW_REG_SSPM_DDREN_REQ_MASK_B,
	PW_REG_SSUSB0_DDREN_REQ_MASK_B,
	PW_REG_UFS_DDREN_REQ_MASK_B,
	PW_REG_VDEC_DDREN_REQ_MASK_B,
	PW_REG_VENC_DDREN_REQ_MASK_B,
	PW_REG_MMSYS_DDREN_REQ_MASK_B,
	PW_REG_CG_CHECK_DDREN_REQ_MASK_B,

	/* SPM_SRC_MASK_1 */
	PW_REG_PERI_APSRC_REQ_MASK_B,
	PW_REG_APU_APSRC_REQ_MASK_B,
	PW_REG_AUDIO_DSP_APSRC_REQ_MASK_B,
	PW_REG_CAM_APSRC_REQ_MASK_B,
	PW_REG_IFR_APSRC_REQ_MASK_B,
	PW_REG_CONN_APSRC_REQ_MASK_B,
	PW_REG_MCUPM_APSRC_REQ_MASK_B,
	PW_REG_DISP0_APSRC_REQ_MASK_B,
	PW_REG_DPM_APSRC_REQ_MASK_B,
	PW_REG_GCE_APSRC_REQ_MASK_B,
	PW_REG_GPUEB_APSRC_REQ_MASK_B,
	PW_REG_IMG_APSRC_REQ_MASK_B,
	PW_REG_INFRASYS_APSRC_REQ_MASK_B,
	PW_REG_MD_APSRC_REQ_MASK_B,
	PW_REG_MDP0_APSRC_REQ_MASK_B,
	PW_REG_MM_PROC_APSRC_REQ_MASK_B,
	PW_REG_MSDC1_APSRC_REQ_MASK_B,
	PW_REG_SCP_APSRC_REQ_MASK_B,
	PW_REG_SSPM_APSRC_REQ_MASK_B,
	PW_REG_SSUSB0_APSRC_REQ_MASK_B,
	PW_REG_UFS_APSRC_REQ_MASK_B,
	PW_REG_VDEC_APSRC_REQ_MASK_B,
	PW_REG_VENC_APSRC_REQ_MASK_B,
	PW_REG_MMSYS_APSRC_REQ_MASK_B,
	PW_REG_CG_CHECK_APSRC_REQ_MASK_B,

	/* SPM_SRC_MASK_2 */
	PW_REG_PERI_VRF18_REQ_MASK_B,
	PW_REG_APU_VRF18_REQ_MASK_B,
	PW_REG_AUDIO_DSP_VRF18_REQ_MASK_B,
	PW_REG_IFR_VRF18_REQ_MASK_B,
	PW_REG_CONN_VRF18_REQ_MASK_B,
	PW_REG_MCUPM_VRF18_REQ_MASK_B,
	PW_REG_DPM_VRF18_REQ_MASK_B,
	PW_REG_GCE_VRF18_REQ_MASK_B,
	PW_REG_GPUEB_VRF18_REQ_MASK_B,
	PW_REG_MD_VRF18_REQ_MASK_B,
	PW_REG_MM_PROC_VRF18_REQ_MASK_B,
	PW_REG_MSDC1_VRF18_REQ_MASK_B,
	PW_REG_SCP_VRF18_REQ_MASK_B,
	PW_REG_SSPM_VRF18_REQ_MASK_B,
	PW_REG_SSUSB0_VRF18_REQ_MASK_B,
	PW_REG_UFS_VRF18_REQ_MASK_B,
	PW_REG_MMSYS_VRF18_REQ_MASK_B,
	PW_REG_CG_CHECK_VRF18_REQ_MASK_B,

	/* SPM_SRC_MASK_3 */
	PW_REG_PERI_INFRA_REQ_MASK_B,
	PW_REG_APU_INFRA_REQ_MASK_B,
	PW_REG_AUDIO_DSP_INFRA_REQ_MASK_B,
	PW_REG_CAM_INFRA_REQ_MASK_B,
	PW_REG_IFR_INFRA_REQ_MASK_B,
	PW_REG_CONN_INFRA_REQ_MASK_B,
	PW_REG_MCUPM_INFRA_REQ_MASK_B,
	PW_REG_DPM_INFRA_REQ_MASK_B,
	PW_REG_GCE_INFRA_REQ_MASK_B,
	PW_REG_GPUEB_INFRA_REQ_MASK_B,
	PW_REG_MD_INFRA_REQ_MASK_B,
	PW_REG_MM_PROC_INFRA_REQ_MASK_B,
	PW_REG_MSDC1_INFRA_REQ_MASK_B,
	PW_REG_SCP_INFRA_REQ_MASK_B,
	PW_REG_SRCCLKENI_INFRA_REQ_MASK_B,
	PW_REG_SSPM_INFRA_REQ_MASK_B,
	PW_REG_SSUSB0_INFRA_REQ_MASK_B,
	PW_REG_UFS_INFRA_REQ_MASK_B,

	/* SPM_SRC_MASK_4 */
	PW_REG_PERI_SRCCLKENA_MASK_B,
	PW_REG_APU_SRCCLKENA_MASK_B,
	PW_REG_AUDIO_DSP_SRCCLKENA_MASK_B,
	PW_REG_IFR_SRCCLKENA_MASK_B,
	PW_REG_CONN_SRCCLKENA_MASK_B,
	PW_REG_CONN_SRCCLKENB_MASK_B,
	PW_REG_MCUPM_SRCCLKENA_MASK_B,
	PW_REG_GPUEB_SRCCLKENA_MASK_B,
	PW_REG_MD_SRCCLKENA_MASK_B,
	PW_REG_MD_SRCCLKENA1_MASK_B,
	PW_REG_MM_PROC_SRCCLKENA_MASK_B,
	PW_REG_MSDC1_SRCCLKENA_MASK_B,
	PW_REG_SCP_SRCCLKENA_MASK_B,
	PW_REG_SRCCLKENI_SRCCLKENA_MASK_B,
	PW_REG_SSPM_SRCCLKENA_MASK_B,
	PW_REG_SSUSB0_SRCCLKENA_MASK_B,
	PW_REG_UFS_SRCCLKENA_MASK_B,
	PW_REG_CG_CHECK_SRCCLKENA_MASK_B,

	/* SPM_SRC_MASK_5 */
	PW_REG_IFR_VCORE_REQ_MASK_B,
	PW_REG_CONN_VCORE_REQ_MASK_B,
	PW_REG_MD_VCORE_REQ_MASK_B,
	PW_REG_CG_CHECK_VCORE_REQ_MASK_B,

	/* SPM_SRC_MASK_6 */
	PW_REG_PERI_EMI_REQ_MASK_B,
	PW_REG_APU_EMI_REQ_MASK_B,
	PW_REG_AUDIO_DSP_EMI_REQ_MASK_B,
	PW_REG_CAM_EMI_REQ_MASK_B,
	PW_REG_IFR_EMI_REQ_MASK_B,
	PW_REG_CONN_EMI_REQ_MASK_B,
	PW_REG_MCUPM_EMI_REQ_MASK_B,
	PW_REG_DISP0_EMI_REQ_MASK_B,
	PW_REG_DPM_EMI_REQ_MASK_B,
	PW_REG_GCE_EMI_REQ_MASK_B,
	PW_REG_GPUEB_EMI_REQ_MASK_B,
	PW_REG_IMG_EMI_REQ_MASK_B,
	PW_REG_INFRASYS_EMI_REQ_MASK_B,
	PW_REG_MD_EMI_REQ_MASK_B,
	PW_REG_MDP0_EMI_REQ_MASK_B,
	PW_REG_MM_PROC_EMI_REQ_MASK_B,
	PW_REG_MSDC1_EMI_REQ_MASK_B,
	PW_REG_SCP_EMI_REQ_MASK_B,
	PW_REG_SSPM_EMI_REQ_MASK_B,
	PW_REG_SSUSB0_EMI_REQ_MASK_B,
	PW_REG_UFS_EMI_REQ_MASK_B,
	PW_REG_VDEC_EMI_REQ_MASK_B,
	PW_REG_VENC_EMI_REQ_MASK_B,
	PW_REG_MMSYS_EMI_REQ_MASK_B,
	PW_REG_CG_CHECK_EMI_REQ_MASK_B,

	/* SPM_SRC_MASK_7 */
	PW_REG_PERI_PMIC_REQ_MASK_B,
	PW_REG_APU_PMIC_REQ_MASK_B,
	PW_REG_AUDIO_DSP_PMIC_REQ_MASK_B,
	PW_REG_CONN_PMIC_REQ_MASK_B,
	PW_REG_MCUPM_PMIC_REQ_MASK_B,
	PW_REG_GPUEB_PMIC_REQ_MASK_B,
	PW_REG_MD_PMIC_REQ_MASK_B,
	PW_REG_MM_PROC_PMIC_REQ_MASK_B,
	PW_REG_MSDC1_PMIC_REQ_MASK_B,
	PW_REG_SCP_PMIC_REQ_MASK_B,
	PW_REG_SRCCLKENI_PMIC_REQ_MASK_B,
	PW_REG_SSPM_PMIC_REQ_MASK_B,
	PW_REG_SSUSB0_PMIC_REQ_MASK_B,
	PW_REG_UFS_PMIC_REQ_MASK_B,
	PW_REG_CG_CHECK_PMIC_REQ_MASK_B,

	/* SPM_SRC_MASK_8 */
	PW_REG_MCUSYS_APSRC_REQ_MASK_B,
	PW_REG_MCUSYS_DDREN_REQ_MASK_B,
	PW_REG_MCUSYS_EMI_REQ_MASK_B,
	PW_REG_DVFSRC_LEVEL_REQ_MASK_B,

	/* SPM_EVENT_CON_MISC */
	PW_REG_SRCCLKEN_FAST_RESP,
	PW_REG_CSYSPWRUP_ACK_MASK,

	/* INFRA_DDREN_REQ_MASK */
	PW_REG_INFRA_MERGE_CCIF_DDREN_REQ_MASK_B,
	PW_REG_INFRA_MERGE_DPMAIF_DDREN_REQ_MASK_B,
	PW_REG_INFRA_MERGE_IPIC_DDREN_REQ_MASK_B,

	/* INFRA_APSRC_REQ_MASK */
	PW_REG_INFRA_MERGE_CCIF_APSRC_REQ_MASK_B,
	PW_REG_INFRA_MERGE_DPMAIF_APSRC_REQ_MASK_B,
	PW_REG_INFRA_MERGE_IPIC_APSRC_REQ_MASK_B,

	/* INFRA_VRF18_REQ_MASK */
	PW_REG_INFRA_MERGE_CCIF_VRF18_REQ_MASK_B,
	PW_REG_INFRA_MERGE_DPMAIF_VRF18_REQ_MASK_B,
	PW_REG_INFRA_MERGE_IPIC_VRF18_REQ_MASK_B,

	/* INFRA_INFRA_REQ_MASK */
	PW_REG_INFRA_MERGE_CCIF_INFRA_REQ_MASK_B,
	PW_REG_INFRA_MERGE_DPMAIF_INFRA_REQ_MASK_B,
	PW_REG_INFRA_MERGE_IPIC_INFRA_REQ_MASK_B,

	/* INFRA_26M_REQ_MASK */
	PW_REG_INFRA_MERGE_CCIF_SRCCLKENA_REQ_MASK_B,
	PW_REG_INFRA_MERGE_DPMAIF_SRCCLKENA_REQ_MASK_B,
	PW_REG_INFRA_MERGE_IPIC_SRCCLKENA_REQ_MASK_B,

	/* INFRA_VCORE_REQ_MASK */
	PW_REG_INFRA_MERGE_CCIF_VCORE_REQ_MASK_B,
	PW_REG_INFRA_MERGE_DPMAIF_VCORE_REQ_MASK_B,
	PW_REG_INFRA_MERGE_IPIC_VCORE_REQ_MASK_B,

	/* PERI_SEC_RSV_0 for afe, msdc, ssusb MASK */
	PW_REG_PERI_MERGE_AFE_SRCCLKENA_REQ_MASK_B,
	PW_REG_PERI_MERGE_MSDC_SRCCLKENA_REQ_MASK_B,
	PW_REG_PERI_MERGE_SSUSB_SRCCLKENA_REQ_MASK_B,
	PW_REG_PERI_MERGE_AFE_INFRA_REQ_MASK_B,
	PW_REG_PERI_MERGE_MSDC_INFRA_REQ_MASK_B,
	PW_REG_PERI_MERGE_SSUSB_INFRA_REQ_MASK_B,
	PW_REG_PERI_MERGE_AFE_VRF18_REQ_MASK_B,
	PW_REG_PERI_MERGE_MSDC_VRF18_REQ_MASK_B,
	PW_REG_PERI_MERGE_SSUSB_VRF18_REQ_MASK_B,
	PW_REG_PERI_MERGE_AFE_APSRC_DDREN_REQ_MASK_B,
	PW_REG_PERI_MERGE_MSDC_APSRC_DDREN_REQ_MASK_B,
	PW_REG_PERI_MERGE_SSUSB_APSRC_DDREN_REQ_MASK_B,

	/* SPM_WAKEUP_EVENT_MASK */
	PW_REG_WAKEUP_EVENT_MASK,

	/* SPM_WAKEUP_EVENT_EXT_MASK */
	PW_REG_EXT_WAKEUP_EVENT_MASK,

	PW_MAX_COUNT,
};


#endif /* __PWR_CTRL_H__ */
