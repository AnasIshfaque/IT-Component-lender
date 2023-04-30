-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Apr 30, 2023 at 03:43 PM
-- Server version: 10.4.24-MariaDB
-- PHP Version: 8.1.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `rfid_read`
--

-- --------------------------------------------------------

--
-- Table structure for table `inventory`
--

CREATE TABLE `inventory` (
  `ID` int(11) NOT NULL,
  `item` varchar(255) DEFAULT NULL,
  `stock` int(11) DEFAULT 5
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `inventory`
--

INSERT INTO `inventory` (`ID`, `item`, `stock`) VALUES
(1, 'Humidity', 7),
(2, 'Transistor', 6),
(3, 'Bluetooth', 3);

-- --------------------------------------------------------

--
-- Table structure for table `orders`
--

CREATE TABLE `orders` (
  `ID` int(11) NOT NULL,
  `item_id` int(11) NOT NULL,
  `quantity` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `orders`
--

INSERT INTO `orders` (`ID`, `item_id`, `quantity`) VALUES
(1, 1, 1),
(45, 2, 3),
(46, 2, 2),
(46, 2, 2),
(51, 1, 2),
(52, 1, 2),
(54, 1, 1),
(54, 2, 5),
(54, 2, 0),
(56, 1, 2),
(57, 1, 1),
(57, 1, 4),
(58, 1, 3),
(58, 2, 3),
(59, 2, 2),
(60, 1, 3),
(62, 1, 9),
(63, 1, 6),
(63, 2, 5),
(63, 2, 5),
(63, 2, 3),
(64, 2, 3),
(64, 1, 5),
(64, 2, 2),
(65, 2, 2),
(65, 1, 4),
(66, 1, 5),
(66, 2, 5),
(67, 1, 5),
(67, 2, 5),
(67, 1, 5),
(67, 2, 5),
(67, 1, 5),
(67, 1, 5),
(67, 2, 1),
(67, 2, 5),
(70, 1, 4),
(70, 2, 5),
(72, 1, 2),
(73, 1, 1),
(75, 1, 3),
(76, 2, 3),
(77, 3, 3),
(78, 3, 3),
(80, 1, 1),
(82, 2, 1),
(84, 3, 1),
(84, 1, 3);

-- --------------------------------------------------------

--
-- Table structure for table `rfid_data`
--

CREATE TABLE `rfid_data` (
  `ID` bigint(20) NOT NULL,
  `Member_ID` varchar(20) DEFAULT NULL,
  `date` timestamp NOT NULL DEFAULT current_timestamp(),
  `state` tinyint(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `rfid_data`
--

INSERT INTO `rfid_data` (`ID`, `Member_ID`, `date`, `state`) VALUES
(42, '672138123\r\n', '2023-04-04 22:40:32', NULL),
(43, '672138123\r\n', '2023-04-04 23:39:31', NULL),
(44, '672138123\r\n', '2023-04-04 23:42:46', NULL),
(45, '672138123\r\n', '2023-04-04 23:44:11', 0),
(46, '672138123\r\n', '2023-04-05 03:41:49', 0),
(47, '672138123\r\n', '2023-04-05 04:49:46', NULL),
(48, '672138123\r\n', '2023-04-05 04:49:56', NULL),
(49, '672138123\r\n', '2023-04-05 04:53:31', NULL),
(50, '672138123\r\n', '2023-04-05 04:58:11', NULL),
(51, '672138123\r\n', '2023-04-05 04:59:35', 0),
(52, '672138123\r\n', '2023-04-05 07:21:14', 0),
(53, '672138123\r\n', '2023-04-05 07:31:25', NULL),
(54, '672138123\r\n', '2023-04-05 07:33:41', 0),
(55, '672138123\r\n', '2023-04-05 08:35:06', NULL),
(56, '672138123\r\n', '2023-04-05 08:36:56', 0),
(57, '672138123\r\n', '2023-04-05 08:42:25', 0),
(58, '672138123\r\n', '2023-04-05 08:48:18', 0),
(59, '672138123\r\n', '2023-04-05 09:01:37', 0),
(60, '672138123\r\n', '2023-04-05 09:11:26', 0),
(61, '672138123\r\n', '2023-04-05 09:14:41', NULL),
(62, '672138123\r\n', '2023-04-05 09:24:48', 0),
(63, '672138123\r\n', '2023-04-05 09:26:14', 0),
(64, '512337823\r\n', '2023-04-07 05:48:39', 0),
(65, '512337823\r\n', '2023-04-07 05:53:30', 0),
(66, '512337823\r\n', '2023-04-07 10:07:42', 0),
(67, '512337823\r\n', '2023-04-07 10:13:39', 0),
(68, '512337823\r\n', '2023-04-07 23:56:04', NULL),
(69, '512337823\r\n', '2023-04-08 00:11:28', NULL),
(70, '512337823\r\n', '2023-04-08 00:14:00', 0),
(71, '512337823\r\n', '2023-04-08 07:31:57', NULL),
(72, '512337823\r\n', '2023-04-08 07:35:08', 0),
(73, '512337823\r\n', '2023-04-08 07:35:38', 0),
(74, '512337823\r\n', '2023-04-08 07:38:27', NULL),
(75, '512337823\r\n', '2023-04-08 09:04:44', 0),
(76, '512337823\r\n', '2023-04-08 09:09:39', 0),
(77, '672138123\r\n', '2023-04-24 08:39:13', 0),
(78, '672138123\r\n', '2023-04-24 08:41:29', 0),
(79, '672138123\r\n', '2023-04-29 08:30:25', NULL),
(80, '672138123\r\n', '2023-04-29 08:37:56', 0),
(81, '672138123\r\n', '2023-04-29 08:50:06', NULL),
(82, '672138123\r\n', '2023-04-29 08:53:58', 0),
(83, '672138123\r\n', '2023-04-29 09:05:42', NULL),
(84, '672138123\r\n', '2023-04-29 09:15:15', 0),
(85, '672138123\r\n', '2023-04-30 02:43:57', NULL),
(86, '672138123\r\n', '2023-04-30 02:46:29', NULL),
(87, '672138123\r\n', '2023-04-30 02:52:00', NULL),
(88, '672138123\r\n', '2023-04-30 02:56:58', NULL),
(89, '672138123\r\n', '2023-04-30 03:00:31', NULL),
(90, '672138123\r\n', '2023-04-30 03:07:19', NULL),
(91, '672138123\r\n', '2023-04-30 03:12:43', NULL),
(92, '672138123\r\n', '2023-04-30 03:22:26', 1),
(93, '672138123\r\n', '2023-04-30 03:35:49', 1),
(94, '672138123\r\n', '2023-04-30 03:44:33', 1),
(95, '672138123\r\n', '2023-04-30 04:00:38', 1),
(96, '672138123\r\n', '2023-04-30 04:07:05', 1),
(97, '672138123\r\n', '2023-04-30 04:12:34', 1),
(98, '672138123\r\n', '2023-04-30 04:16:15', 1),
(99, '672138123\r\n', '2023-04-30 04:19:16', 1),
(100, '672138123\r\n', '2023-04-30 04:26:57', 1),
(101, '672138123\r\n', '2023-04-30 04:29:41', 1),
(102, '672138123\r\n', '2023-04-30 04:38:39', 1),
(103, '672138123\r\n', '2023-04-30 04:48:38', 1);

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
  `S_ID` varchar(10) NOT NULL,
  `RFID` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`S_ID`, `RFID`) VALUES
('011203001', '2272463615\r\n'),
('011203003', '512337823\r\n'),
('011203002', '672138123\r\n');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `inventory`
--
ALTER TABLE `inventory`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `rfid_data`
--
ALTER TABLE `rfid_data`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`S_ID`),
  ADD UNIQUE KEY `RFID` (`RFID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `rfid_data`
--
ALTER TABLE `rfid_data`
  MODIFY `ID` bigint(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=104;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
