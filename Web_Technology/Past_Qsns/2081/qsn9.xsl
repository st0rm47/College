<?xml version = "1.0" encoding = "UTF-8"?>
<xsl:stylesheet xmlns:xsl = "http://www.w3.org/1999/XSL/Transform">
<xsl:output method = "html"/>
<xsl:template match = "/">
    <html>
        <head>
            <title> Student Details</title>
        </head>
        <body>
            <h1> Students </h1>
            <table border = "1">
                <tr>
                    <td>ID</td>
                    <td>Name</td>
                    <td>Age</td>
                    <td>City</td>
                    <td>Zipcode</td>
                </tr>
            
                <xsl:for-each select = "students/student">
                    <tr>
                        <td><xsl:value-of select = "@id"/></td>
                        <td><xsl:value-of select = "student/name"/></td>
                        <td><xsl:value-of select = "student/age"/></td>
                        <td><xsl:value-of select = "address/city"/></td>
                        <td><xsl:value-of select = "address/zipcode"/></td> 
                    </tr>
                </xsl:for-each>
            </table>
        </body>
    </html>
</xsl:template>
</xsl:stylesheet>