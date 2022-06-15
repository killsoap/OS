-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema Gitar_base
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema Gitar_base
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `Gitar_base` DEFAULT CHARACTER SET utf8 ;
USE `Gitar_base` ;

-- -----------------------------------------------------
-- Table `Gitar_base`.`Покраска`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Gitar_base`.`Покраска` (
  `id_Покраски` INT ZEROFILL UNSIGNED NOT NULL,
  `Тип_покраски` VARCHAR(45) NOT NULL,
  `Цена` INT NOT NULL,
  PRIMARY KEY (`id_Покраски`),
  UNIQUE INDEX `id_Покраски_UNIQUE` (`id_Покраски` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Gitar_base`.`Анкер`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Gitar_base`.`Анкер` (
  `id_Анкера` INT ZEROFILL UNSIGNED NOT NULL,
  `Тип_Анкера` VARCHAR(45) NOT NULL,
  `Цена` INT NOT NULL,
  PRIMARY KEY (`id_Анкера`),
  UNIQUE INDEX `id_Анкера_UNIQUE` (`id_Анкера` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Gitar_base`.`Бридж`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Gitar_base`.`Бридж` (
  `id_Бриджа` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Модель` VARCHAR(45) NOT NULL,
  `Фирма` VARCHAR(45) NOT NULL,
  `Цена` INT NOT NULL,
  PRIMARY KEY (`id_Бриджа`),
  UNIQUE INDEX `id_Грифа_UNIQUE` (`id_Бриджа` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Gitar_base`.`Вид_сборки`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Gitar_base`.`Вид_сборки` (
  `id_Сборки` INT ZEROFILL UNSIGNED NOT NULL,
  `Тип_сборки` VARCHAR(45) NOT NULL,
  `Цена` INT NOT NULL,
  PRIMARY KEY (`id_Сборки`),
  UNIQUE INDEX `id_Анкера_UNIQUE` (`id_Сборки` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Gitar_base`.`Звукосниматель`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Gitar_base`.`Звукосниматель` (
  `id_Звукоснимателя` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Модель` VARCHAR(45) NOT NULL,
  `Фирма` VARCHAR(45) NOT NULL,
  `Цена` INT NOT NULL,
  PRIMARY KEY (`id_Звукоснимателя`),
  UNIQUE INDEX `id_Грифа_UNIQUE` (`id_Звукоснимателя` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Gitar_base`.`Колки`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Gitar_base`.`Колки` (
  `id_Колков` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Модель` VARCHAR(45) NOT NULL,
  `Фирма` VARCHAR(45) NOT NULL,
  `Цена` INT NOT NULL,
  PRIMARY KEY (`id_Колков`),
  UNIQUE INDEX `id_Грифа_UNIQUE` (`id_Колков` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Gitar_base`.`Материал_грифа`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Gitar_base`.`Материал_грифа` (
  `id_Грифа` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Материал` VARCHAR(45) NOT NULL,
  `Цена` INT NOT NULL,
  PRIMARY KEY (`id_Грифа`),
  UNIQUE INDEX `id_Грифа_UNIQUE` (`id_Грифа` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Gitar_base`.`Материал_корпуса`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Gitar_base`.`Материал_корпуса` (
  `id_корпуса` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Материал` VARCHAR(45) NOT NULL,
  `Цена` INT NOT NULL,
  PRIMARY KEY (`id_корпуса`),
  UNIQUE INDEX `id_Грифа_UNIQUE` (`id_корпуса` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Gitar_base`.`Сотрудники`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Gitar_base`.`Сотрудники` (
  `id_Сотрудника` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `ФИО` VARCHAR(45) NOT NULL,
  `Должность` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id_Сотрудника`),
  UNIQUE INDEX `id_Сотрудника_UNIQUE` (`id_Сотрудника` ASC) VISIBLE,
  UNIQUE INDEX `ФИО_UNIQUE` (`ФИО` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Gitar_base`.`Струны`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Gitar_base`.`Струны` (
  `id_Струн` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Модель` VARCHAR(45) NOT NULL,
  `Фирма` VARCHAR(45) NOT NULL,
  `Цена` INT NOT NULL,
  PRIMARY KEY (`id_Струн`),
  UNIQUE INDEX `id_Грифа_UNIQUE` (`id_Струн` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Gitar_base`.`Электроника`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Gitar_base`.`Электроника` (
  `id_Электроники` INT UNSIGNED ZEROFILL NOT NULL,
  `Конфигурация` VARCHAR(45) NOT NULL,
  `Цена` INT NOT NULL,
  PRIMARY KEY (`id_Электроники`),
  UNIQUE INDEX `id_Электроники_UNIQUE` (`id_Электроники` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Gitar_base`.`Заказ`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Gitar_base`.`Заказ` (
  `id_заказа` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `ФИО_Клиента` VARCHAR(45) NOT NULL,
  `Телефон` VARCHAR(12) NOT NULL,
  `Дата_заказа` DATE NOT NULL,
  `Подтверждение_оплаты` TINYINT NULL,
  `Сотрудник` INT UNSIGNED NOT NULL,
  `Материал_грифа` INT UNSIGNED NULL,
  `Материал_корпуса` INT UNSIGNED NULL,
  `Колки` INT UNSIGNED NULL,
  `Звукосниматели` INT UNSIGNED NULL,
  `Анкер` INT UNSIGNED NULL,
  `Бридж` INT UNSIGNED NULL,
  `Электроника` INT UNSIGNED NULL,
  `Покраска` INT UNSIGNED NULL,
  `Струны` INT UNSIGNED NULL,
  `Вид_сборки` INT UNSIGNED NULL,
  PRIMARY KEY (`id_заказа`),
  UNIQUE INDEX `id_заказа_UNIQUE` (`id_заказа` ASC) VISIBLE,
  INDEX `Покраска_idx` (`Покраска` ASC) VISIBLE,
  INDEX `Анкер_idx` (`Анкер` ASC) VISIBLE,
  INDEX `Бридж_idx` (`Бридж` ASC) VISIBLE,
  INDEX `Вид_сборки_idx` (`Вид_сборки` ASC) VISIBLE,
  INDEX `Звукосниматель_idx` (`Звукосниматели` ASC) VISIBLE,
  INDEX `Колки_idx` (`Колки` ASC) VISIBLE,
  INDEX `Материал_грифа_idx` (`Материал_грифа` ASC) VISIBLE,
  INDEX `Материал_корпуса_idx` (`Материал_корпуса` ASC) VISIBLE,
  INDEX `Сотрудник_idx` (`Сотрудник` ASC) VISIBLE,
  INDEX `Струны_idx` (`Струны` ASC) VISIBLE,
  INDEX `Электроника_idx` (`Электроника` ASC) VISIBLE,
  CONSTRAINT `Покраска`
    FOREIGN KEY (`Покраска`)
    REFERENCES `Gitar_base`.`Покраска` (`id_Покраски`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `Анкер`
    FOREIGN KEY (`Анкер`)
    REFERENCES `Gitar_base`.`Анкер` (`id_Анкера`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `Бридж`
    FOREIGN KEY (`Бридж`)
    REFERENCES `Gitar_base`.`Бридж` (`id_Бриджа`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `Вид_сборки`
    FOREIGN KEY (`Вид_сборки`)
    REFERENCES `Gitar_base`.`Вид_сборки` (`id_Сборки`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `Звукосниматель`
    FOREIGN KEY (`Звукосниматели`)
    REFERENCES `Gitar_base`.`Звукосниматель` (`id_Звукоснимателя`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `Колки`
    FOREIGN KEY (`Колки`)
    REFERENCES `Gitar_base`.`Колки` (`id_Колков`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `Материал_грифа`
    FOREIGN KEY (`Материал_грифа`)
    REFERENCES `Gitar_base`.`Материал_грифа` (`id_Грифа`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `Материал_корпуса`
    FOREIGN KEY (`Материал_корпуса`)
    REFERENCES `Gitar_base`.`Материал_корпуса` (`id_корпуса`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `Сотрудник`
    FOREIGN KEY (`Сотрудник`)
    REFERENCES `Gitar_base`.`Сотрудники` (`id_Сотрудника`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `Струны`
    FOREIGN KEY (`Струны`)
    REFERENCES `Gitar_base`.`Струны` (`id_Струн`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `Электроника`
    FOREIGN KEY (`Электроника`)
    REFERENCES `Gitar_base`.`Электроника` (`id_Электроники`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
