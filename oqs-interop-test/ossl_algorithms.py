key_exchanges = [
    'oqs_kem_default', 'p256_oqs_kem_default',
##### OQS_TEMPLATE_FRAGMENT_KEX_ALGS_START
    # post-quantum key exchanges
    'frodo640aes','frodo640shake','frodo976aes','frodo976shake','frodo1344aes','frodo1344shake','bike1l1cpa','bike1l3cpa','bike1l1fo','bike1l3fo','kyber512','kyber768','kyber1024','newhope512cca','newhope1024cca','ntru_hps2048509','ntru_hps2048677','ntru_hps4096821','ntru_hrss701','lightsaber','saber','firesaber','sidhp434','sidhp503','sidhp610','sidhp751','sikep434','sikep503','sikep610','sikep751','kyber90s512','kyber90s768','kyber90s1024','babybear','mamabear','papabear','babybearephem','mamabearephem','papabearephem','oqkd_frodo640aes','oqkd_frodo640shake','oqkd_frodo976aes','oqkd_frodo976shake','oqkd_frodo1344aes','oqkd_frodo1344shake','oqkd_kyber512','oqkd_kyber768','oqkd_kyber1024','oqkd_kyber90s512','oqkd_kyber90s768','oqkd_kyber90s1024','oqkd_ntru_hps2048509','oqkd_ntru_hps2048677','oqkd_ntru_hps4096821','oqkd_ntru_hrss701','oqkd_lightsaber','oqkd_saber','oqkd_firesaber',
    # post-quantum + classical key exchanges
    'p256_frodo640aes','p256_frodo640shake','p384_frodo976aes','p384_frodo976shake','p521_frodo1344aes','p521_frodo1344shake','p256_bike1l1cpa','p384_bike1l3cpa','p256_bike1l1fo','p384_bike1l3fo','p256_kyber512','p384_kyber768','p521_kyber1024','p256_newhope512cca','p521_newhope1024cca','p256_ntru_hps2048509','p384_ntru_hps2048677','p521_ntru_hps4096821','p384_ntru_hrss701','p256_lightsaber','p384_saber','p521_firesaber','p256_sidhp434','p256_sidhp503','p384_sidhp610','p521_sidhp751','p256_sikep434','p256_sikep503','p384_sikep610','p521_sikep751','p256_kyber90s512','p384_kyber90s768','p521_kyber90s1024','p256_babybear','p384_mamabear','p521_papabear','p256_babybearephem','p384_mamabearephem','p521_papabearephem','p256_oqkd_frodo640aes','p256_oqkd_frodo640shake','p384_oqkd_frodo976aes','p384_oqkd_frodo976shake','p521_oqkd_frodo1344aes','p521_oqkd_frodo1344shake','p256_oqkd_kyber512','p384_oqkd_kyber768','p521_oqkd_kyber1024','p256_oqkd_kyber90s512','p384_oqkd_kyber90s768','p521_oqkd_kyber90s1024','p256_oqkd_ntru_hps2048509','p384_oqkd_ntru_hps2048677','p521_oqkd_ntru_hps4096821','p384_oqkd_ntru_hrss701','p256_oqkd_lightsaber','p384_oqkd_saber','p521_oqkd_firesaber',
##### OQS_TEMPLATE_FRAGMENT_KEX_ALGS_END
]
signatures = [
##### OQS_TEMPLATE_FRAGMENT_PQ_SIG_ALGS_START
    'oqs_sig_default',
    'dilithium2',
    'dilithium3',
    'dilithium4',
    'falcon512',
    'falcon1024',
    'mqdss3148',
    'picnicl1full',
    'picnic3l1',
    'qteslapi',
    'qteslapiii',
    'rainbowIaclassic',
    'rainbowVcclassic',
    'sphincsharaka128frobust',
##### OQS_TEMPLATE_FRAGMENT_PQ_SIG_ALGS_END
]
