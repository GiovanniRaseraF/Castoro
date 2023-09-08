-- Authors: 
-- + Giovanni Rasera : c++ code
-- + Lorenzo Mancini : database and specifications

-- Links:
-- + https://github.com/GiovanniRaseraF
-- + https://github.com/MancioLollo

-- -----------------------------------------------------
-- Database castorodb
-- -----------------------------------------------------
DROP DATABASE IF EXISTS castorodb;

-- -----------------------------------------------------
-- Database castorodb
-- -----------------------------------------------------
CREATE DATABASE IF NOT EXISTS castorodb;

-- -----------------------------------------------------
-- Set castorodb
-- -----------------------------------------------------
SET search_path TO castorodb;

-- -----------------------------------------------------
-- Table bro
-- -----------------------------------------------------
DROP TABLE IF EXISTS bro;

CREATE TABLE IF NOT EXISTS bro (
  id_bro SERIAL NOT NULL,
  nome VARCHAR(16) NOT NULL,
  cognome VARCHAR(16) NOT NULL,
  create_time TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
  lista_soprannomi VARCHAR(500) NULL,
  extend_text VARCHAR(45) NULL,
  extend_text_copy1 VARCHAR(45) NULL,
  extend_text_copy2 VARCHAR(45) NULL,
  extend_int INT NULL,
  extend_int_copy1 INT NULL,
  extend_int_copy2 INT NULL,
  extend_date TIMESTAMP NULL,
  extend_date_copy1 TIMESTAMP NULL,
  extend_date_copy2 TIMESTAMP NULL,
  PRIMARY KEY (id_bro));

-- -----------------------------------------------------
-- Table story
-- -----------------------------------------------------
DROP TABLE IF EXISTS story;

CREATE TABLE IF NOT EXISTS story (
  id_story SERIAL NOT NULL,
  title VARCHAR(500) NOT NULL,
  story_date DATE NOT NULL,
  story TEXT NOT NULL,
  create_time TIMESTAMP NOT NULL,
  tag VARCHAR(100) NULL,
  PRIMARY KEY (id_story));

-- -----------------------------------------------------
-- Table tell
-- -----------------------------------------------------
DROP TABLE IF EXISTS tell;

CREATE TABLE IF NOT EXISTS tell (
  bro INT NOT NULL,
  story INT NOT NULL,
  PRIMARY KEY (bro, story),
  CONSTRAINT fk_bro_tell_story
    FOREIGN KEY (bro)
    REFERENCES bro(id_bro)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT fk_story_tell_bro
    FOREIGN KEY (story)
    REFERENCES story(id_story)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);