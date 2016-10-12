-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Client :  127.0.0.1
-- Généré le :  Ven 09 Octobre 2015 à 13:56
-- Version du serveur :  5.6.17
-- Version de PHP :  5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données :  `gestnotes`
--

-- --------------------------------------------------------

--
-- Structure de la table `admin`
--

CREATE TABLE IF NOT EXISTS `admin` (
  `id` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `person_detail_id` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `admin`
--

INSERT INTO `admin` (`id`, `password`, `person_detail_id`) VALUES
('admin1', '61b115da227a57859490c53251490fffe66c6d67', 4);

-- --------------------------------------------------------

--
-- Structure de la table `contact`
--

CREATE TABLE IF NOT EXISTS `contact` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `person_detail_id` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Contenu de la table `contact`
--

INSERT INTO `contact` (`id`, `person_detail_id`) VALUES
(1, 3),
(3, 7);

-- --------------------------------------------------------

--
-- Structure de la table `course`
--

CREATE TABLE IF NOT EXISTS `course` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `coeff_ce` float NOT NULL,
  `coeff_de` float NOT NULL,
  `coeff_tp` float NOT NULL,
  `coeff_project` float NOT NULL,
  `teacher_id` varchar(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Contenu de la table `course`
--

INSERT INTO `course` (`id`, `name`, `coeff_ce`, `coeff_de`, `coeff_tp`, `coeff_project`, `teacher_id`) VALUES
(1, 'C++', 0, 0.8, 0.2, 0, 'teacher1'),
(2, 'UML 2', 0, 0.4, 0.3, 0.3, 'teacher1');

-- --------------------------------------------------------

--
-- Structure de la table `groups`
--

CREATE TABLE IF NOT EXISTS `groups` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=7 ;

--
-- Contenu de la table `groups`
--

INSERT INTO `groups` (`id`, `name`) VALUES
(1, 'Groupe A'),
(4, 'Groupe B'),
(6, 'Groupe C');

-- --------------------------------------------------------

--
-- Structure de la table `l_course_teacher_assistant`
--

CREATE TABLE IF NOT EXISTS `l_course_teacher_assistant` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `course_id` int(11) NOT NULL,
  `teacher_id` varchar(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=30 ;

--
-- Contenu de la table `l_course_teacher_assistant`
--

INSERT INTO `l_course_teacher_assistant` (`id`, `course_id`, `teacher_id`) VALUES
(28, 1, 'teacher2'),
(29, 2, 'teacher2');

-- --------------------------------------------------------

--
-- Structure de la table `l_group_course`
--

CREATE TABLE IF NOT EXISTS `l_group_course` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `group_id` int(11) NOT NULL,
  `course_id` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=76 ;

--
-- Contenu de la table `l_group_course`
--

INSERT INTO `l_group_course` (`id`, `group_id`, `course_id`) VALUES
(72, 1, 1),
(73, 1, 2),
(74, 4, 2),
(75, 6, 2);

-- --------------------------------------------------------

--
-- Structure de la table `mark`
--

CREATE TABLE IF NOT EXISTS `mark` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `type` int(11) NOT NULL,
  `value` float NOT NULL,
  `coeff` float NOT NULL,
  `student_id` int(11) NOT NULL,
  `course_id` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=37 ;

--
-- Contenu de la table `mark`
--

INSERT INTO `mark` (`id`, `type`, `value`, `coeff`, `student_id`, `course_id`) VALUES
(26, 2, 16, 0.4, 20130089, 2),
(27, 3, 16, 0.3, 20130089, 2),
(28, 4, 10, 0.3, 20130089, 2),
(29, 3, 20, 0.2, 20130091, 1),
(30, 2, 20, 0.8, 20130091, 1),
(31, 2, 14, 0.4, 20130090, 2),
(32, 3, 10, 0.3, 20130090, 2),
(33, 4, 15, 0.3, 20130090, 2),
(34, 4, 20, 0.3, 20130091, 2),
(35, 3, 20, 0.3, 20130091, 2),
(36, 2, 10, 0.4, 20130091, 2);

-- --------------------------------------------------------

--
-- Structure de la table `person_detail`
--

CREATE TABLE IF NOT EXISTS `person_detail` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `firstname` varchar(255) NOT NULL,
  `address` varchar(255) NOT NULL,
  `city` varchar(255) NOT NULL,
  `postal_code` varchar(255) NOT NULL,
  `country` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `avatar` varchar(255) NOT NULL,
  `phone_home` varchar(32) NOT NULL,
  `phone_mobile` varchar(32) NOT NULL,
  `date_born` varchar(32) NOT NULL,
  `date_register` varchar(32) NOT NULL,
  `gender` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=12 ;

--
-- Contenu de la table `person_detail`
--

INSERT INTO `person_detail` (`id`, `name`, `firstname`, `address`, `city`, `postal_code`, `country`, `email`, `avatar`, `phone_home`, `phone_mobile`, `date_born`, `date_register`, `gender`) VALUES
(1, 'Beaujean', 'Fabien', '1 allée des mûriers', 'Verrières-le-Buisson', '91370', 'France', 'fabien.beaujean@efrei.net', '/public/img/avatar.png', '0169307310', '0786027310', '20/07/1995', '25/05/2015', 0),
(2, 'Lepoivre', 'Franck', '1 allée des mûriers', 'paris', '75008', 'France', 'franck.lepoivre@gmail.com', '/public/img/user.png', '0189567854', '0645732409', '20/09/1965', '25/05/2015', 0),
(3, 'Beaujean', 'Franck', '1 allée des mûriers', 'Verrières-le-Buisson', '91370', 'France', 'franck.beaujean@yahoo.fr', '/public/img/user.png', '', '', '', '', 0),
(4, 'Stow', 'William', '5 rue moufetard', 'Paris', '75005', 'France', 'willima.stow@efrei.net', '/public/img/user.png', '0786027337', '0786027337', '', '', 0),
(7, 'Lorentz', 'Papa', '34 avenue de la charette', 'Versailles', '78007', 'France', 'papa.lorentz@yahoo.fr', '', '0189567854', '0680567854', '', '', 0),
(8, 'Luc', 'Lorentz', '1 allée des mûriers', 'Versailles', '78007', 'France', 'luc.lorentz@hotmail.com', '/public/img/avatar.png', '0189567854', '0689567854', '22/04/2015', '25/05/2015', 0),
(9, 'test', 'test', 'test', 'sdfsdsd', '70000', 'dlgkmsd', 'test@test.com', '/public/img/avatar.png', '0956789876', '0956789876', '05/06/1996', '25/05/2015', 0),
(11, 'Teller', 'Georges', '5 rue du marin', 'Sceaux', '92000', 'France', 'g.teller@yahoo.fr', '/public/img/avatar.png', '0123456789', '0654734589', '23/04/1955', '25/05/2015', 0);

-- --------------------------------------------------------

--
-- Structure de la table `report_card`
--

CREATE TABLE IF NOT EXISTS `report_card` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `student_id` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=11 ;

--
-- Contenu de la table `report_card`
--

INSERT INTO `report_card` (`id`, `student_id`) VALUES
(10, 20130089);

-- --------------------------------------------------------

--
-- Structure de la table `student`
--

CREATE TABLE IF NOT EXISTS `student` (
  `id` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `success_year` int(11) NOT NULL DEFAULT '0',
  `person_detail_id` int(11) NOT NULL,
  `contact_id` int(11) NOT NULL,
  `group_id` int(11) NOT NULL DEFAULT '0',
  `teacher_id` varchar(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `student`
--

INSERT INTO `student` (`id`, `password`, `success_year`, `person_detail_id`, `contact_id`, `group_id`, `teacher_id`) VALUES
('20130089', '61b115da227a57859490c53251490fffe66c6d67', 0, 1, 1, 4, 'teacher1'),
('20130090', '61b115da227a57859490c53251490fffe66c6d67', 0, 8, 3, 6, 'teacher1'),
('20130091', '61b115da227a57859490c53251490fffe66c6d67', 0, 9, 3, 1, 'teacher1');

-- --------------------------------------------------------

--
-- Structure de la table `teacher`
--

CREATE TABLE IF NOT EXISTS `teacher` (
  `id` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `person_detail_id` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `teacher`
--

INSERT INTO `teacher` (`id`, `password`, `person_detail_id`) VALUES
('teacher1', '4af011ab61cc2c6ddbfb72466fa7f93963fd0376', 2),
('teacher2', '61b115da227a57859490c53251490fffe66c6d67', 11);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
