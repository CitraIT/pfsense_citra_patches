--- /etc/inc/notices.inc.orig    2022-04-29 19:52:54.937978000 -0300
+++ /etc/inc/notices.inc 2022-04-29 20:15:49.728255000 -0300
@@ -464,22 +464,28 @@
        }

        $url = "https://api.telegram.org/bot{$config['notifications']['telegram']['api']}/sendMessage?";
-       $data = array(
-               "chat_id" => $config['notifications']['telegram']['chatid'],
-               "text" => "{$config['system']['hostname']}.{$config['system']['domain']}\n{$message}"
-       );
-       $result = json_decode(curl_post_notification($url . http_build_query($data)), true);
-       if (is_array($result)) {
-               if ($result['ok']) {
-                       unset($err_msg);
+
+       $chat_ids = explode(":", $config['notifications']['telegram']['chatid']);
+       foreach($chat_ids as $chatid) {
+               $data = array(
+                       "chat_id" => $chatid,
+                       "text" => "{$config['system']['hostname']}.{$config['system']['domain']}\n{$message}"
+               );
+               $result = json_decode(curl_post_notification($url . http_build_query($data)), true);
+               if (is_array($result)) {
+                       if ($result['ok']) {
+                               unset($err_msg);
+                       } else {
+                               $err_msg = sprintf(gettext("Failed to send Telegram notification. Error received was :{$result['error_code']}: {$result['description']}"));
+                               log_error($err_msg);
+                       }
                } else {
-                       $err_msg = sprintf(gettext("Failed to send Telegram notification. Error received was :{$result['error_code']}: {$result['description']}"));
+                       $err_msg = gettext("API to Telegram did not return data in expected format!");
                        log_error($err_msg);
                }
-       } else {
-               $err_msg = gettext("API to Telegram did not return data in expected format!");
-               log_error($err_msg);
        }
+
+
        return $err_msg;
 }

