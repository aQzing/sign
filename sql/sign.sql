/*
Navicat MySQL Data Transfer

Source Server         : localhost3306
Source Server Version : 50540
Source Host           : localhost:3306
Source Database       : sign

Target Server Type    : MYSQL
Target Server Version : 50540
File Encoding         : 65001

Date: 2021-04-14 11:32:03
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for user_sign
-- ----------------------------
DROP TABLE IF EXISTS `user_sign`;
CREATE TABLE `user_sign` (
  `id` varchar(20) NOT NULL COMMENT '学号',
  `name` varchar(50) NOT NULL COMMENT '姓名',
  `location` varchar(255) DEFAULT '' COMMENT '打卡位置',
  `time` datetime DEFAULT NULL COMMENT '打卡时间'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of user_sign
-- ----------------------------
INSERT INTO `user_sign` VALUES ('123456', '张三', '中关村', '2021-03-06 15:58:05');
INSERT INTO `user_sign` VALUES ('1231441', '张三', '北京中关村', '2021-10-25 15:24:11');
INSERT INTO `user_sign` VALUES ('1231441', '李四', '北京中关村', '2021-10-25 15:24:11');
INSERT INTO `user_sign` VALUES ('2131315123', 'qzing', '', null);
INSERT INTO `user_sign` VALUES ('fsdf', 'fdsfsdf', '', null);
INSERT INTO `user_sign` VALUES ('dfsf', 'dfsdfs', '', null);
INSERT INTO `user_sign` VALUES ('100206', '王麻子', '', '2021-03-08 14:44:28');
INSERT INTO `user_sign` VALUES ('fsdfds', 'dfsdf', '浙江省杭州市江干区钱江路', '2021-03-08 15:18:10');
INSERT INTO `user_sign` VALUES ('fs', 'fdsf', '浙江省杭州市江干区钱江路', '2021-03-08 15:47:01');
INSERT INTO `user_sign` VALUES ('1002112', '嘀嘀嘀', '浙江省杭州市江干区钱江路', '2021-03-09 20:40:56');
INSERT INTO `user_sign` VALUES ('1002112', '嘀嘀嘀2', '浙江省杭州市江干区钱江路', '2021-03-09 20:50:43');
INSERT INTO `user_sign` VALUES ('12131313', '宁宁', '浙江省杭州市江干区钱江路', '2021-03-09 20:53:29');
INSERT INTO `user_sign` VALUES ('12131313', '小花', '浙江省杭州市江干区钱江路', '2021-03-09 20:54:17');
INSERT INTO `user_sign` VALUES ('1894664', '托尼', '浙江省金华市义乌市', '2021-03-10 10:21:38');
INSERT INTO `user_sign` VALUES ('12558', '高尔基', '浙江省金华市义乌市', '2021-03-10 10:22:55');
INSERT INTO `user_sign` VALUES ('ts12312344', '宋钟基', null, '2021-03-10 11:15:24');
