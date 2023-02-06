-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Feb 05, 2022 at 09:46 PM
-- Server version: 5.7.36
-- PHP Version: 7.4.26

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `project`
--

-- --------------------------------------------------------

--
-- Table structure for table `accomodation`
--

DROP TABLE IF EXISTS `accomodation`;
CREATE TABLE IF NOT EXISTS `accomodation` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(50) NOT NULL,
  `title` varchar(50) NOT NULL,
  `prefecture` varchar(50) NOT NULL,
  `address` varchar(50) NOT NULL,
  `number` varchar(10) NOT NULL,
  `guest` int(11) DEFAULT NULL,
  `length` double NOT NULL,
  `width` double NOT NULL,
  `review` int(11) NOT NULL,
  `pool` tinyint(1) NOT NULL,
  `sauna` tinyint(1) NOT NULL,
  `parking` tinyint(1) NOT NULL,
  `gym` tinyint(1) NOT NULL,
  `id_img` varchar(100) NOT NULL,
  PRIMARY KEY (`id`,`username`)
) ENGINE=MyISAM AUTO_INCREMENT=636 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `accomodation`
--

INSERT INTO `accomodation` (`id`, `username`, `title`, `prefecture`, `address`, `number`, `guest`, `length`, `width`, `review`, `pool`, `sauna`, `parking`, `gym`, `id_img`) VALUES
(633, 'nikolas2', 'headervila1', 'pierias', 'sofoklis 56', '6979845624', 9, 5.8887, 5.9647, 4, 0, 1, 1, 0, 'headervila1.jpg'),
(631, 'nikolas2', 'Vila1', 'Utrect', 'river 51', '699999999', 5, 2.5987, 4.68518, 4, 1, 1, 0, 0, 'vila1.jpg');

-- --------------------------------------------------------

--
-- Table structure for table `image`
--

DROP TABLE IF EXISTS `image`;
CREATE TABLE IF NOT EXISTS `image` (
  `id` varchar(250) NOT NULL,
  `username` varchar(50) NOT NULL,
  `description` mediumtext NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `image`
--

INSERT INTO `image` (`id`, `username`, `description`) VALUES
('vila1.jpg', 'nikolas2', 'vila1'),
('vila2.jpg', 'nikolas2', 'vila2'),
('headervila1.jpg', 'nikolas2', 'Headervila1');

-- --------------------------------------------------------

--
-- Table structure for table `registration`
--

DROP TABLE IF EXISTS `registration`;
CREATE TABLE IF NOT EXISTS `registration` (
  `username` varchar(50) CHARACTER SET latin1 COLLATE latin1_general_cs NOT NULL,
  `password` varchar(100) NOT NULL,
  `salt` varchar(500) NOT NULL,
  `email` varchar(50) NOT NULL,
  `active` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`username`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `registration`
--

INSERT INTO `registration` (`username`, `password`, `salt`, `email`, `active`) VALUES
('nikolas2', '$6$DokSalt$MxdhbRZ8UKAc2E9/j8aAl5fbo5vnYsfq9B6hHJZxvfCZVhVlHP0KDKWNWZWhswtyIcGhpIrHmirKSHDsLW/pu1', '$6$DokSalt', 'yourEmail@gmail.com', 1);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
