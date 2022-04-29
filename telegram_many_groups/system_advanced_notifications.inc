--- /usr/local/pfSense/include/www/system_advanced_notifications.inc.orig      2022-04-29 20:27:05.154373000 -0300
+++ /usr/local/pfSense/include/www/system_advanced_notifications.inc   2022-04-29 18:48:02.213289000 -0300
@@ -243,7 +243,7 @@
                if (preg_replace("/[^a-zA-Z0-9_:\-]/", "", $config['notifications']['telegram']['api']) !== $config['notifications']['telegram']['api']) {
                        $input_errors[] = gettext("The only special characters permitted in the Telegram API string are _, - and :");
                }
-               if (preg_replace("/[^a-zA-Z0-9@_\-]/", "", $config['notifications']['telegram']['chatid']) !== $config['notifications']['telegram']['chatid']) {
+               if (preg_replace("/[^a-zA-Z0-9@_:\-]/", "", $config['notifications']['telegram']['chatid']) !== $config['notifications']['telegram']['chatid']) {
                        $input_errors[] = gettext("The Chat ID can only contain @, _ or - as special characters");
                }
