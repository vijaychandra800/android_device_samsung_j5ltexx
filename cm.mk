# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

$(call inherit-product, device/samsung/o7lte/full_o7lte.mk)

PRODUCT_BUILD_PROP_OVERRIDES += PRODUCT_NAME=o7lte TARGET_DEVICE=o7lte

PRODUCT_NAME := cm_o7lte
