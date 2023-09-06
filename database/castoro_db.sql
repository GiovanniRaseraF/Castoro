-- -----------------------------------------------------
-- Schema castorodb
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS castorodb ;

-- -----------------------------------------------------
-- Schema castorodb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS castorodb ;

SET search_path to DB;

-- -----------------------------------------------------
-- Table user
-- -----------------------------------------------------
DROP TABLE IF EXISTS castorodb.user;

CREATE TABLE IF NOT EXISTS castorodb.user (
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
DROP TABLE IF EXISTS castorodb.stories;

CREATE TABLE IF NOT EXISTS castorodb.stories (
  id_story SERIAL NOT NULL,
  title VARCHAR(500) NOT NULL,
  story_date DATE NOT NULL,
  story TEXT NOT NULL,
  create_time TIMESTAMP NOT NULL,
  tag VARCHAR(100) NULL,
  PRIMARY KEY (id_story));


-- -----------------------------------------------------
-- Table user_has_stories
-- -----------------------------------------------------
DROP TABLE IF EXISTS castorodb.user_has_stories;

CREATE TABLE IF NOT EXISTS castorodb.user_has_stories (
  user_id_user INT NOT NULL,
  stories_id_story INT NOT NULL,
  PRIMARY KEY (user_id_user, stories_id_story),
  CONSTRAINT fk_user_has_stories_user
    FOREIGN KEY (user_id_user)
    REFERENCES castorodb.user(id_user)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT fk_user_has_stories_stories1
    FOREIGN KEY (stories_id_story)
    REFERENCES castorodb.stories(id_story)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);