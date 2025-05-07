<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * Localized language
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** Database username */
define( 'DB_USER', 'wpuser' );

/** Database password */
define( 'DB_PASSWORD', 'password' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',          '1#neZ@8<vL9LcLm<1h]P_P<>e?L`b01xXzQ*F-Pdb&31H|I.VO/ v-`PCM:I,+5n' );
define( 'SECURE_AUTH_KEY',   '7:FujHyDll :LKHSK[..IQ6ec[vZV?iXe4JHtffxoM_Hn<Od)jffXP%tI+akF3VC' );
define( 'LOGGED_IN_KEY',     'g`W-Mzf,9-QZc42/ajtoz/LeO2]pMMMxJWjQuFDL&q,)Cl+1b?yoaWR:.H|xil@5' );
define( 'NONCE_KEY',         '@#8*xg4G<fT5}!/Wr.Bp0/`_fFNs/f|iToM/5J|] |X!$AM-t,)HF7oguLBp,j&_' );
define( 'AUTH_SALT',         '?ID2]DI0GNpP8PpzI9z].7t@>16Oop<uT%EoD<-x<9XHcH~TRX*}yXvSu[UxAhfA' );
define( 'SECURE_AUTH_SALT',  '*8aLw*0zNy[#kEuSEo0%qPh!QBu1RiV3Co#EstR}-nvd&v*x2}}+i~E^S[jnaFjO' );
define( 'LOGGED_IN_SALT',    '&}cgz)Wi.pJ0aNm6AYts#uuKU>CaQc)v]$6%[T*$Or-`WxftB|usK Fy~f^PKHq$' );
define( 'NONCE_SALT',        '7Ndd3V+H8$NByVpoYdEv&Hoq*R}eqZ2<mpCjgzrBwBe`(*AOGwmM38m8Fk;=mxg+' );
define( 'WP_CACHE_KEY_SALT', 'o03RwVo*Ol<=H5]SRc=}j`#5CQ::|2YMoGH+J8D}ON%(s~ac[n3!f}dZm<nKjQqy' );


/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';


/* Add any custom values between this line and the "stop editing" line. */



/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
if ( ! defined( 'WP_DEBUG' ) ) {
	define( 'WP_DEBUG', false );
}

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
