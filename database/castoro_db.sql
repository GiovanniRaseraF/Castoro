-- MySQL Script generated by MySQL Workbench
-- Tue Sep  5 21:54:58 2023
-- Model: New Model    Version: 1.0
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS `mydb` ;

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`user`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `mydb`.`user` ;

CREATE TABLE IF NOT EXISTS `mydb`.`user` (
  `id_user` INT NOT NULL AUTO_INCREMENT,
  `nome` VARCHAR(16) NOT NULL,
  `cognome` VARCHAR(16) NOT NULL,
  `create_time` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `extend_text` VARCHAR(45) NULL,
  `extend_text_copy1` VARCHAR(45) NULL,
  `extend_text_copy2` VARCHAR(45) NULL,
  `extend_int` INT NULL,
  `extend_int_copy1` INT NULL,
  `extend_int_copy2` INT NULL,
  `extend_date` TIMESTAMP NULL,
  `extend_date_copy1` TIMESTAMP NULL,
  `extend_date_copy2` TIMESTAMP NULL,
  PRIMARY KEY (`id_user`));


-- -----------------------------------------------------
-- Table `mydb`.`stories`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `mydb`.`stories` ;

CREATE TABLE IF NOT EXISTS `mydb`.`stories` (
  `id_story` INT NOT NULL AUTO_INCREMENT,
  `title` VARCHAR(500) NOT NULL,
  `story` LONGTEXT NOT NULL,
  `story_date` DATE NOT NULL,
  `create_time` TIMESTAMP NOT NULL,
  `year` YEAR NULL,
  `month` INT NULL,
  `tag` VARCHAR(100) NULL,
  PRIMARY KEY (`id_story`));


-- -----------------------------------------------------
-- Table `mydb`.`user_has_stories`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `mydb`.`user_has_stories` ;

CREATE TABLE IF NOT EXISTS `mydb`.`user_has_stories` (
  `user_id_user` INT NOT NULL,
  `stories_id_story` INT NOT NULL,
  PRIMARY KEY (`user_id_user`, `stories_id_story`),
  INDEX `fk_user_has_stories_stories1_idx` (`stories_id_story` ASC) VISIBLE,
  INDEX `fk_user_has_stories_user_idx` (`user_id_user` ASC) VISIBLE,
  CONSTRAINT `fk_user_has_stories_user`
    FOREIGN KEY (`user_id_user`)
    REFERENCES `mydb`.`user` (`id_user`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_user_has_stories_stories1`
    FOREIGN KEY (`stories_id_story`)
    REFERENCES `mydb`.`stories` (`id_story`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
