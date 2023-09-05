-- -----------------------------------------------------
-- Database castorodb
-- -----------------------------------------------------
DROP database if exists castorodb;
create database castorodb;

-- -----------------------------------------------------
-- Table user
-- -----------------------------------------------------
DROP TABLE IF EXISTS user;

CREATE TABLE IF NOT EXISTS user (
  id_user SERIAL NOT NULL,
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
  PRIMARY KEY (id_user));


-- -----------------------------------------------------
-- Table stories
-- -----------------------------------------------------
DROP TABLE IF EXISTS stories;

CREATE TABLE IF NOT EXISTS stories (
  id_story SERIAL NOT NULL,
  title VARCHAR(500) NOT NULL,
  story_date DATE NOT NULL,
  story LONGTEXT NOT NULL,
  create_time TIMESTAMP NOT NULL,
  year YEAR NULL,
  month INT NULL,
  tag VARCHAR(100) NULL,
  PRIMARY KEY (id_story));


-- -----------------------------------------------------
-- Table user_has_stories
-- -----------------------------------------------------
DROP TABLE IF EXISTS user_has_stories;

CREATE TABLE IF NOT EXISTS user_has_stories (
  user_id_user INT NOT NULL,
  stories_id_story INT NOT NULL,
  PRIMARY KEY (user_id_user, stories_id_story),
  CONSTRAINT fk_user_has_stories_user
    FOREIGN KEY (user_id_user)
    REFERENCES user(id_user)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT fk_user_has_stories_stories1
    FOREIGN KEY (stories_id_story)
    REFERENCES stories(id_story)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);