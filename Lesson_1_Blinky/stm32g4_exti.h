#ifndef STM32G4_EXTI_H
#define STM32G4_EXTI_H

#include "main.h"

#define EXTI_LINE_0                         (EXTI_GPIO     | EXTI_REG1 | 0x00u)
#define EXTI_LINE_1                         (EXTI_GPIO     | EXTI_REG1 | 0x01u)
#define EXTI_LINE_2                         (EXTI_GPIO     | EXTI_REG1 | 0x02u)
#define EXTI_LINE_3                         (EXTI_GPIO     | EXTI_REG1 | 0x03u)
#define EXTI_LINE_4                         (EXTI_GPIO     | EXTI_REG1 | 0x04u)
#define EXTI_LINE_5                         (EXTI_GPIO     | EXTI_REG1 | 0x05u)
#define EXTI_LINE_6                         (EXTI_GPIO     | EXTI_REG1 | 0x06u)
#define EXTI_LINE_7                         (EXTI_GPIO     | EXTI_REG1 | 0x07u)
#define EXTI_LINE_8                         (EXTI_GPIO     | EXTI_REG1 | 0x08u)
#define EXTI_LINE_9                         (EXTI_GPIO     | EXTI_REG1 | 0x09u)
#define EXTI_LINE_10                        (EXTI_GPIO     | EXTI_REG1 | 0x0Au)
#define EXTI_LINE_11                        (EXTI_GPIO     | EXTI_REG1 | 0x0Bu)
#define EXTI_LINE_12                        (EXTI_GPIO     | EXTI_REG1 | 0x0Cu)
#define EXTI_LINE_13                        (EXTI_GPIO     | EXTI_REG1 | 0x0Du)
#define EXTI_LINE_14                        (EXTI_GPIO     | EXTI_REG1 | 0x0Eu)
#define EXTI_LINE_15                        (EXTI_GPIO     | EXTI_REG1 | 0x0Fu)
#define EXTI_LINE_16                        (EXTI_CONFIG   | EXTI_REG1 | 0x10u)
#define EXTI_LINE_17                        (EXTI_CONFIG   | EXTI_REG1 | 0x11u)
#define EXTI_LINE_18                        (EXTI_DIRECT   | EXTI_REG1 | 0x12u)
#define EXTI_LINE_19                        (EXTI_CONFIG   | EXTI_REG1 | 0x13u)
#define EXTI_LINE_20                        (EXTI_CONFIG   | EXTI_REG1 | 0x14u)
#define EXTI_LINE_21                        (EXTI_CONFIG   | EXTI_REG1 | 0x15u)
#define EXTI_LINE_22                        (EXTI_CONFIG   | EXTI_REG1 | 0x16u)
#define EXTI_LINE_23                        (EXTI_DIRECT   | EXTI_REG1 | 0x17u)
#define EXTI_LINE_24                        (EXTI_DIRECT   | EXTI_REG1 | 0x18u)
#define EXTI_LINE_25                        (EXTI_DIRECT   | EXTI_REG1 | 0x19u)
#define EXTI_LINE_26                        (EXTI_DIRECT   | EXTI_REG1 | 0x1Au)
#define EXTI_LINE_27                        (EXTI_DIRECT   | EXTI_REG1 | 0x1Bu)
#define EXTI_LINE_28                        (EXTI_DIRECT   | EXTI_REG1 | 0x1Cu)
#define EXTI_LINE_29                        (EXTI_CONFIG   | EXTI_REG1 | 0x1Du)
#define EXTI_LINE_30                        (EXTI_CONFIG   | EXTI_REG1 | 0x1Eu)
#define EXTI_LINE_31                        (EXTI_CONFIG   | EXTI_REG1 | 0x1Fu)
#define EXTI_LINE_32                        (EXTI_CONFIG   | EXTI_REG2 | 0x00u)
#define EXTI_LINE_33                        (EXTI_CONFIG   | EXTI_REG2 | 0x01u)
#define EXTI_LINE_34                        (EXTI_DIRECT   | EXTI_REG2 | 0x02u)
#define EXTI_LINE_35                        (EXTI_DIRECT   | EXTI_REG2 | 0x03u)
#define EXTI_LINE_36                        (EXTI_DIRECT   | EXTI_REG2 | 0x04u)
#define EXTI_LINE_37                        (EXTI_DIRECT   | EXTI_REG2 | 0x05u)
#define EXTI_LINE_38                        (EXTI_CONFIG   | EXTI_REG2 | 0x06u)
#define EXTI_LINE_39                        (EXTI_CONFIG   | EXTI_REG2 | 0x07u)
#define EXTI_LINE_40                        (EXTI_CONFIG   | EXTI_REG2 | 0x08u)
#define EXTI_LINE_41                        (EXTI_CONFIG   | EXTI_REG2 | 0x09u)
#define EXTI_LINE_42                        (EXTI_DIRECT   | EXTI_REG2 | 0x0Au)
#define EXTI_LINE_43                        (EXTI_DIRECT   | EXTI_REG2 | 0x0Bu)

#define EXTI_MODE_NONE                      0x00000000U
#define EXTI_MODE_INTERRUPT                 0x00000001U
#define EXTI_MODE_EVENT                     0x00000002U

#define EXTI_TRIGGER_NONE                   0x00000000U
#define EXTI_TRIGGER_RISING                 0x00000001U
#define EXTI_TRIGGER_FALLING                0x00000002U
#define EXTI_TRIGGER_RISING_FALLING         (EXTI_TRIGGER_RISING | EXTI_TRIGGER_FALLING)

#define EXTI_GPIOA                          0x00000000U
#define EXTI_GPIOB                          0x00000001U
#define EXTI_GPIOC                          0x00000002U
#define EXTI_GPIOD                          0x00000003U
#define EXTI_GPIOE                          0x00000004U
#define EXTI_GPIOF                          0x00000005U
#define EXTI_GPIOG                          0x00000006U

#define EXTI_PROPERTY_SHIFT                 24U
#define EXTI_DIRECT                         (0x01uL << EXTI_PROPERTY_SHIFT)
#define EXTI_CONFIG                         (0x02uL << EXTI_PROPERTY_SHIFT)
#define EXTI_GPIO                           ((0x04uL << EXTI_PROPERTY_SHIFT) | EXTI_CONFIG)
#define EXTI_RESERVED                       (0x08uL << EXTI_PROPERTY_SHIFT)
#define EXTI_PROPERTY_MASK                  (EXTI_DIRECT | EXTI_CONFIG | EXTI_GPIO)

#define EXTI_REG_SHIFT                      16U
#define EXTI_REG1                           (0x00uL << EXTI_REG_SHIFT)
#define EXTI_REG2                           (0x01uL << EXTI_REG_SHIFT)
#define EXTI_REG_MASK                       (EXTI_REG1 | EXTI_REG2)
#define EXTI_PIN_MASK                       0x0000001FU

#define EXTI_MODE_MASK                      (EXTI_MODE_EVENT | EXTI_MODE_INTERRUPT)

#define EXTI_TRIGGER_MASK                   (EXTI_TRIGGER_RISING | EXTI_TRIGGER_FALLING)

#define EXTI_LINE_NB                        44UL

#endif /* STM32G4_EXTI_H */
